## First Come First Serve (FCFS) Scheduling Algorithm

## Introduction
First Come First Serve (FCFS) is one of the simplest CPU scheduling algorithms. As the name suggests, in this algorithm, the process that arrives first in the ready queue is executed first. It operates on a **non-preemptive** basis, meaning once a process starts executing, it cannot be interrupted until it completes.

---

## Characteristics
1. **Type**: Non-preemptive.
2. **Order**: Processes are executed in the order they arrive.
3. **Data Structure**: Queue (FIFO - First In First Out).
4. **Priority**: Arrival time determines the priority.

---

## Advantages
1. Simple to implement and easy to understand.
2. Fair for processes as it processes them in the order of arrival.

---

## Disadvantages
1. **Convoy Effect**: If a long process arrives first, shorter processes must wait, leading to longer average waiting times.
2. Poor CPU utilization if the first process is I/O-bound.
3. Does not account for process priorities or execution time.

---

## Key Terms
- **Arrival Time (AT)**: The time at which a process enters the ready queue.
- **Burst Time (BT)**: The time required by a process to complete execution.
- **Completion Time (CT)**: The time at which a process finishes execution.
- **Turnaround Time (TAT)**: The total time taken by a process from arrival to completion.
  - **Formula**: `TAT = CT - AT`
- **Waiting Time (WT)**: The total time a process spends waiting in the ready queue.
  - **Formula**: `WT = TAT - BT`

---

## Example

### Process Table
| Process | Arrival Time (AT) | Burst Time (BT) |
|---------|--------------------|-----------------|
| P1      | 0                 | 4               |
| P2      | 1                 | 3               |
| P3      | 2                 | 1               |
| P4      | 3                 | 2               |

### Gantt Chart

### Calculations
| Process | Arrival Time (AT) | Burst Time (BT) | Completion Time (CT) | Turnaround Time (TAT) | Waiting Time (WT) |
|---------|--------------------|-----------------|-----------------------|-----------------------|-------------------|
| P1      | 0                 | 4               | 4                     | 4                     | 0                 |
| P2      | 1                 | 3               | 7                     | 6                     | 3                 |
| P3      | 2                 | 1               | 8                     | 6                     | 5                 |
| P4      | 3                 | 2               | 10                    | 7                     | 5                 |

### Averages
- **Average Turnaround Time (TAT)**:  
  \[
  \text{Average TAT} = \frac{4 + 6 + 6 + 7}{4} = 5.75
  \]

- **Average Waiting Time (WT)**:  
  \[
  \text{Average WT} = \frac{0 + 3 + 5 + 5}{4} = 3.25
  \]

---

## Summary
- **FCFS** is simple and easy to implement but suffers from poor efficiency due to the convoy effect.
- Best suited for batch systems where fairness and simplicity are priorities.

--- 

## Pseudocode
```plaintext
1. Input the number of processes (n).
2. For each process, input Arrival Time (AT) and Burst Time (BT).
3. Sort processes by Arrival Time (AT).
4. For each process in the sorted order:
   a. Calculate Completion Time (CT).
   b. Calculate Turnaround Time (TAT = CT - AT).
   c. Calculate Waiting Time (WT = TAT - BT).
5. Compute average TAT and WT.
6. Display the process schedule and averages.

