# SIMATS Engineering – Operating Systems (CSA04)
## Assignment 4 – CO4: Optimising File Storage and Disk Access

**Student Name:** B. Lokeshwaran  
**Register Number:** 192424305  
**Course:** Operating Systems (CSA04)  
**Submission Date:** 19-11-2026  

---

## Repository Structure

```text
CSA04-192424305-Assignment4/
├── README.md
├── docs/
│   └── Operating_Systems_Assignment_4_CO4.pdf
├── figures/
│   ├── fig3_college_directory_tree.png
│   ├── fig5_block_allocation_comparison.png
│   ├── fig9_disk_scheduling_paths.png
│   └── fig12_video_streaming_delivery.png
├── outputs/
│   ├── task2_allocation_and_math_output.txt
│   ├── task4_disk_scheduling_output.txt
│   └── task6_streaming_calculations_output.txt
├── Task1_FileSystem_Design_Review/
│   ├── README.md
│   └── setup_college_hierarchy.sh
├── Task2_File_Allocation_Surveillance/
│   ├── file_allocation_sim.c
│   └── storage_math.py
├── Task3_Modern_File_Systems/
│   ├── README.md
│   └── inspect_filesystem.sh
├── Task4_Disk_Scheduling_Algorithms/
│   ├── disk_scheduling.c
│   └── simulate_10k_requests.py
├── Task5_Distributed_Cloud_Storage/
│   └── README.md
└── Task6_Video_Streaming_Storage/
    └── streaming_capacity_calc.py
```

## Build & Execution Commands

1. **Task 2 – Contiguous vs. Indexed File Allocation (`gcc -std=c11 -Wall -Wextra`):**
   ```bash
   gcc -std=c11 -Wall -Wextra Task2_File_Allocation_Surveillance/file_allocation_sim.c -o file_allocation_sim
   ./file_allocation_sim
   python3 Task2_File_Allocation_Surveillance/storage_math.py
   ```
2. **Task 3 – Real Linux File-System Inspection:**
   ```bash
   chmod +x Task3_Modern_File_Systems/inspect_filesystem.sh
   ./Task3_Modern_File_Systems/inspect_filesystem.sh
   ```
3. **Task 4 – Disk Scheduling Algorithms & 10,000-Request Simulation:**
   ```bash
   gcc -std=c11 -Wall -Wextra Task4_Disk_Scheduling_Algorithms/disk_scheduling.c -o disk_scheduling
   ./disk_scheduling
   python3 Task4_Disk_Scheduling_Algorithms/simulate_10k_requests.py
   ```
4. **Task 6 – Lecture-Video Streaming Storage & Seek Calculations:**
   ```bash
   python3 Task6_Video_Streaming_Storage/streaming_capacity_calc.py
   ```
