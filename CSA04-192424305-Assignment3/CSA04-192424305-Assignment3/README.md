# SIMATS Engineering – Operating Systems (CSA04)
## Assignment 3 – CO3: Memory Management, Virtual Memory & Linking

**Student Name:** B. Lokeshwaran  
**Register Number:** 192424305  
**Course:** Operating Systems (CSA04)  
**Course Outcome:** CO3  

---

## Repository Structure

```text
CSA04-192424305-Assignment3/
├── README.md
├── docs/
│   └── Operating_Systems_Assignment_3_B_Lokeshwaran.pdf
├── figures/
│   ├── fig1_static_dynamic_linking.png
│   ├── fig3_paging_translation.png
│   ├── fig4_segmented_paging.png
│   ├── fig5_demand_paging_flow.png
│   └── fig6_page_replacement_comparison.png
├── outputs/
│   ├── q1_linking_loading_output.txt
│   ├── q2_paging_output.txt
│   ├── q3_segmentation_output.txt
│   ├── q4_virtual_memory_output.txt
│   ├── q5_page_replacement_output.txt
│   └── q7_mlock_latency_output.txt
├── Q1_Linking_Loading_Binding/
│   ├── build_and_test.sh
│   ├── crypto_demo.c
│   ├── main.c
│   └── runtime_load.c
├── Q2_Paging/
│   ├── paging.c
│   └── paging_calculations.py
├── Q3_Segmentation/
│   └── segmentation.c
├── Q4_Virtual_Memory_Demand_Paging/
│   ├── demand_paging_eat.py
│   └── page_touch.c
├── Q5_Page_Replacement/
│   └── replacement.c
├── Q6_Disk_Management/
│   └── README.md
└── Q7_Memory_Management_Plan/
    └── lock_test.c
```

## Build & Reproduction Steps

1. **Q1 – Static, Dynamic (`-fPIC`), and Runtime (`dlopen`/`dlsym`) Linking:**
   ```bash
   chmod +x Q1_Linking_Loading_Binding/build_and_test.sh
   ./Q1_Linking_Loading_Binding/build_and_test.sh
   ```
2. **Q2 – Paging Address Translation & EAT Calculations:**
   ```bash
   gcc -std=c11 -Wall -Wextra Q2_Paging/paging.c -o paging && ./paging
   python3 Q2_Paging/paging_calculations.py
   ```
3. **Q3 – Segmentation Table Translation:**
   ```bash
   gcc -std=c11 -Wall -Wextra Q3_Segmentation/segmentation.c -o segmentation && ./segmentation
   ```
4. **Q4 – Demand Paging & Memory Touch Test:**
   ```bash
   gcc -O0 -Wall -Wextra Q4_Virtual_Memory_Demand_Paging/page_touch.c -o page_touch && ./page_touch 64
   python3 Q4_Virtual_Memory_Demand_Paging/demand_paging_eat.py
   ```
5. **Q5 – Page-Replacement Simulator (FIFO, LRU, Clock, Optimal & Belady's Anomaly):**
   ```bash
   gcc -std=c11 -Wall -Wextra Q5_Page_Replacement/replacement.c -o replacement && ./replacement
   ```
6. **Q7 – Real-Time Memory Locking (`mlock`) Latency Benchmark:**
   ```bash
   gcc -O2 -Wall -Wextra Q7_Memory_Management_Plan/lock_test.c -o lock_test
   ./lock_test unlocked
   ./lock_test lock
   ```
