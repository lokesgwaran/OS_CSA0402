#!/usr/bin/env bash
set -euo pipefail

threshold=85
usage=$(df -P / | awk 'NR==2 {gsub("%","",$5); print $5}')
if [ "$usage" -ge "$threshold" ]; then
    echo "WARNING: root filesystem at ${usage}%"
else
    echo "Disk OK: ${usage}% used"
fi
