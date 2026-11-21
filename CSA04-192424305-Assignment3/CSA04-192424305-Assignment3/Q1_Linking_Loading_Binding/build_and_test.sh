#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"

gcc -fPIC -Wall -Wextra -c crypto_demo.c -o crypto_demo.o
ar rcs libcrypto_demo.a crypto_demo.o
gcc -Wall -Wextra main.c ./libcrypto_demo.a -o app_static

gcc -shared -o libcrypto_demo.so crypto_demo.o
gcc -Wall -Wextra main.c -L. -lcrypto_demo -Wl,-rpath,'$ORIGIN' -o app_dynamic

gcc -Wall -Wextra runtime_load.c -ldl -o runtime_load

echo "=== Binary Sizes ==="
ls -lh app_static app_dynamic runtime_load libcrypto_demo.a libcrypto_demo.so
echo "=== Dynamic Dependencies (ldd) ==="
ldd ./app_dynamic
echo "=== Running app_static ==="
./app_static
echo "=== Running app_dynamic ==="
./app_dynamic
echo "=== Running runtime_load (dlopen/dlsym) ==="
./runtime_load
