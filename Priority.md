# Priority CPU Scheduling

## Definition
Priority CPU Scheduling is a scheduling algorithm where each process is assigned a priority, and the CPU is allocated to the process with the highest priority. Lower numerical values typically denote higher priority, but this can vary depending on implementation.

---

## Key Features
1. **Preemptive or Non-Preemptive:**
   - **Preemptive:** The CPU can be preempted if a new process arrives with a higher priority.
   - **Non-Preemptive:** The CPU will finish the current process before switching to a higher-priority process.

2. **Priority Assignment:**
   - **Static Priority:** Assigned at process creation and does not change.
   - **Dynamic Priority:** Changes based on criteria like time spent waiting.

---

## Steps in Priority Scheduling
1. Assign priorities to all processes.
2. Sort the processes in the **ready queue** based on their priorities.
3. Execute the process with the **highest priority**.
4. Repeat until all processes are executed.

---

## Advantages
- **Flexibility:** Allows prioritization of important processes.
- **Efficient for critical tasks:** High-priority processes get quick access to the CPU.

---

## Disadvantages
- **Starvation:** Low-priority processes may never execute.
- **Overhead:** Requires maintaining priority levels and sorting the ready queue.

---

## Example

### Processes:
| Process | Burst Time | Priority |
|---------|------------|----------|
| P1      | 5 ms       | 3        |
| P2      | 8 ms       | 1        |
| P3      | 4 ms       | 2        |

### Execution Order:
Based on priorities, the order of execution is **P2 → P3 → P1**.

### Gantt Chart:
***| P2 | P3 | P1 | 0 8 12 17***


### Average Waiting Time (AWT):
1. **P2:** 0 ms
2. **P3:** 8 ms
3. **P1:** 12 ms

**AWT = (0 + 8 + 12) / 3 = 6.67 ms**

---

## Conclusion
Priority Scheduling ensures that critical tasks are executed first, making it suitable for time-sensitive operations. However, care must be taken to address issues like starvation using techniques like aging.
