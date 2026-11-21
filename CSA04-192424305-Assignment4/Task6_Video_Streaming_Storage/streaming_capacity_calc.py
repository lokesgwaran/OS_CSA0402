# Task 6.7, 6.8, 6.9: Lecture Video Streaming Storage, Throughput & Seek Calculator
videos = 10000
avg_size_gb = 1.0
replicas = 3
raw_tb = (videos * avg_size_gb) / 1000.0
replicated_tb = raw_tb * replicas

concurrent_viewers = 20000
avg_bitrate_mbps = 3.0
total_gbps = (concurrent_viewers * avg_bitrate_mbps) / 1000.0

video_minutes = 60
segment_sec = 4
total_segments = (video_minutes * 60) // segment_sec
seek_time_sec = 30 * 60
target_segment_idx = seek_time_sec // segment_sec

print(f"Raw Video Library Size (10,000 x 1 GB): {raw_tb:.1f} TB")
print(f"3-Replica Durable Storage Footprint   : {replicated_tb:.1f} TB")
print(f"Peak Streaming Bandwidth (20k @ 3Mbps): {total_gbps:.1f} Gbit/s")
print(f"60-min Video Segments (4s each)       : {total_segments} segments")
print(f"Minute 30 (1,800s) Target Segment Idx : {target_segment_idx} (0-based)")
