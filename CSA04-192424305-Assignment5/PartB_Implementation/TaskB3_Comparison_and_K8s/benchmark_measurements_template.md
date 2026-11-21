# Task B3.2 – Deployment Comparison Measurement Log

| Metric | Bare Linux | VM | Container |
| :--- | :---: | :---: | :---: |
| Startup time | `<record via time>` | `<record via VM boot log>` | `<record via docker run>` |
| Memory footprint | `<record via free -h / ps>` | `<record via hypervisor>` | `<record via docker stats>` |
| Disk/image size | `<record via du -sh>` | `<record via qcow2/vdi size>` | `<record via docker images>` |
| Requests/s (`ab -n 1000 -c 20`) | `<record actual RPS>` | `<record actual RPS>` | `<record actual RPS>` |
