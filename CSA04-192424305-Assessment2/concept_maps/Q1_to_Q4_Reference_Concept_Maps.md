# Questions 1–4: Supplementary Concept Maps (CSA04 – CO1)

## Question 1: Multi-Level Concept Map (OS Types -> OS Structures -> System Calls -> OS Functions)
- **OS Types** (Batch, Time-Sharing, Real-Time, Distributed) *determine architectural goals for* **OS Structures** (Monolithic, Layered, Microkernel, Modular).
- **OS Structures** *govern how* **System Calls** *are dispatched* (e.g., Monolithic kernels execute direct trap handlers in kernel space, whereas Microkernels route requests via IPC message passing).
- **System Calls** *invoke core* **OS Functions** (Process scheduling, virtual memory management, file systems, and device I/O).

## Question 2: Core OS Subsystems & Interdependencies
- **Process Management** (`fork`, `exec`, `wait`) *requests address spaces from* **Memory Management** (`brk`, `mmap`), *reads binaries from* **File System** (`open`, `read`), *and blocks on* **I/O System** (`ioctl`, interrupts).

## Question 3: Comparative Concept Map of OS Types
| OS Type | Core Mechanism | Key Advantage | Primary Limitation |
| :--- | :--- | :--- | :--- |
| **Batch OS** | Groups similar jobs for non-interactive execution | High throughput for long-running jobs | No user interaction; high turnaround delay |
| **Time-Sharing OS** | Preemptive CPU time-slicing across users | Fast interactive response time | Context-switching overhead; scheduling complexity |
| **Distributed OS** | Coordinates networked nodes as a single system | Resource sharing, scalability, fault tolerance | Network latency, synchronization & security overhead |
| **Real-Time OS (RTOS)** | Priority-driven deterministic task scheduling | Guaranteed bounded response deadlines | Limited general-purpose multitasking flexibility |

## Question 4: Dynamic System Call Execution Flow
`User Program API` --(calls library wrapper)--> `System Call Interface` --(software interrupt / syscall trap; switches User Mode to Kernel Mode)--> `Kernel` --(validates parameters & dispatches service routine)--> `Hardware` --(executes I/O / memory operation & raises completion interrupt)--> `Response back to User` --(restores user context & returns status code/errno).
