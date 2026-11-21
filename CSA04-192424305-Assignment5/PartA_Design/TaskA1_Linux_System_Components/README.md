# Task A1 – Evaluate the Linux System Components
- **Architecture:** User Applications -> Shell / Utilities / System Libraries -> Linux Kernel (CFS scheduler, virtual memory/page cache, VFS, device drivers, networking stack) -> Hardware.
- **Process & Memory:** Completely Fair Scheduler (CFS) balances virtual runtime across runnable tasks; `/proc` and `/sys` expose kernel telemetry.
- **Filesystem & Security:** Standard FHS layout (`/`, `/etc`, `/var`, `/usr`, `/proc`, `/sys`), owner/group/other permissions (`chmod`, `chown`), least-privilege `sudo`, and cautious `setuid` usage.
- **Evaluation:** Preferred over Windows Server for lightweight footprint, native automation, and zero per-core licensing overhead.
