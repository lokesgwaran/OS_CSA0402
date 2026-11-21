# Question 5: Hierarchical + Functional Concept Map for System Calls

**Student Name:** B. Lokeshwaran  
**Register Number:** 192424305  
**Course:** CSA04 – Operating Systems (Assessment Tool 2, CO1)  

## 1. Hierarchical & Functional Concept Map

```text
                        OPERATING SYSTEM (OS)
                                  |
                                  v
                        SYSTEM CALL INTERFACE
         +------------------------+------------------------+------------------------+
         |                        |                        |                        |
         v                        v                        v                        v
   PROCESS CALLS             FILE CALLS              DEVICE CALLS           INFORMATION CALLS
         |                        |                        |                        |
         v                        v                        v                        v
  - Create Process         - Open File              - Access Devices         - Get System Information
  - Execute Process        - Read / Write           - Read / Write           - Get Process ID
  - Terminate Process      - Close File             - Control Devices        - Get System Time
         |                        |                        |                        |
         v                        v                        v                        v
  - CPU Scheduling         - File Management        - Device Handling        - System Status Monitoring
  - Memory Allocation      - Disk Management        - I/O Management         - Kernel Accounting
         |                        |                        |                        |
         +------------------------+------------------------+------------------------+
                                  |
                                  v
                        EFFICIENT OS SERVICES
```

## 2. Functional Relationship Summary

| System Call Category | Main Function | Representative System Calls | Related OS Service |
| :--- | :--- | :--- | :--- |
| **Process** | Creates, executes, synchronizes, and terminates processes | `fork()`, `exec()`, `wait()`, `exit()` | CPU scheduling and memory allocation |
| **File** | Creates, opens, reads, writes, repositions, and closes files | `open()`, `read()`, `write()`, `lseek()`, `close()` | File system and secondary storage/disk management |
| **Device** | Requests, releases, reads, writes, and configures hardware devices | `ioctl()`, `read()`, `write()`, `mmap()` | Device drivers and I/O subsystem handling |
| **Information** | Retrieves and updates system metadata, timers, and process attributes | `getpid()`, `uname()`, `gettimeofday()`, `sysinfo()` | System monitoring, accounting, and status management |

## 3. Conclusion
System calls act as a protected bridge between user applications and the OS kernel. Process calls support process execution and scheduling, file calls manage persistent data, device calls control hardware peripherals, and information calls expose system and process state. Together, they coordinate CPU time, memory, storage, and devices efficiently.
