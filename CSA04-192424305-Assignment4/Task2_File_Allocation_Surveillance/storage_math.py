# Task 2.6, 2.7, 2.8, 2.11 Storage & Inode Calculations
file_bytes = 4 * (1024**3)
block_bytes = 4096
num_blocks = file_bytes // block_bytes

ptrs_per_block = block_bytes // 4
direct = 12
single_ind = ptrs_per_block
double_ind = ptrs_per_block ** 2
triple_ind = ptrs_per_block ** 3
total_inode_blocks = direct + single_ind + double_ind + triple_ind
max_inode_tib = (total_inode_blocks * block_bytes) / (1024**4)

disk_4tib_blocks = (4 * (1024**4)) // block_bytes
bitmap_mib = (disk_4tib_blocks // 8) / (1024**2)
fat_gib = (disk_4tib_blocks * 4) / (1024**3)

print(f"4 GiB File Blocks (4 KiB/block): {num_blocks:,}")
print(f"Max Inode Addressable Blocks   : {total_inode_blocks:,} ({max_inode_tib:.3f} TiB)")
print(f"4 TiB Free-Space Bitmap Size   : {bitmap_mib:.0f} MiB")
print(f"4 TiB In-Memory FAT Size       : {fat_gib:.0f} GiB")
