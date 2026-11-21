#include <stdio.h>
#include <dlfcn.h>

typedef void (*encrypt_fn)(void);

int main(void) {
    void *handle = dlopen("./libcrypto_demo.so", RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }
    dlerror(); /* clear old error */
    encrypt_fn encrypt = (encrypt_fn)dlsym(handle, "encrypt_demo");
    const char *err = dlerror();
    if (err) {
        fprintf(stderr, "dlsym failed: %s\n", err);
        dlclose(handle);
        return 1;
    }
    encrypt();
    dlclose(handle);
    return 0;
}
