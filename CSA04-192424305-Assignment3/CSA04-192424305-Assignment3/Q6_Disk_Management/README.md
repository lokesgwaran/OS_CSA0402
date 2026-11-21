# Q6 – Disk Management
- **Boot Sequence:** Firmware -> Bootloader -> Kernel + initramfs -> Root Filesystem mount.
- **RAID Analysis (6 × 4 TB drives):** RAID 0 (24 TB, no redundancy), RAID 1 (12 TB, 3 mirrored pairs), RAID 5 (20 TB, 1 parity disk), RAID 10 (12 TB, recommended for hospital database IOPS & rapid rebuilds).
