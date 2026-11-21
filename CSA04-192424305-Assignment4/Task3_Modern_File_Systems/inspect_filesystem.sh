#!/usr/bin/env bash
# Task 3.9: Linux File-System Inspection Commands
set -euo pipefail

echo "=== Block Devices and Filesystems ==="
lsblk -f

echo "=== Inode Usage ==="
df -i

echo "=== Sample File Metadata ==="
touch /tmp/sample_co4.txt
ls -i /tmp/sample_co4.txt
stat /tmp/sample_co4.txt
rm -f /tmp/sample_co4.txt
