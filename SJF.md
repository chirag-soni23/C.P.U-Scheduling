
# Shortest Job First (SJF) Scheduling

## 📝 Definition
Shortest Job First (SJF) is a CPU scheduling algorithm where the process with the shortest burst time is executed first. 
It is also known as **Shortest Job Next (SJN)**.

---

## 🚦 Types of SJF Scheduling

1. **Non-Preemptive SJF**
   - Once a process starts execution, it runs till completion.
   - Example: A queue where processes are executed one by one in order of their burst times.

2. **Preemptive SJF (Shortest Remaining Time First - SRTF)**
   - The CPU switches to a new process if it has a shorter remaining burst time than the current process.

---

## ✅ Advantages
- Minimizes average waiting time.
- Reduces turnaround time compared to other scheduling algorithms.

---

## ❌ Disadvantages
- **Starvation**: Longer processes may never get executed if short processes keep coming.
- **Difficult Implementation**: Requires prior knowledge of burst times, which is not always available.

---

## 📊 Example

### Given Processes:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1      | 0            | 7          |
| P2      | 2            | 4          |
| P3      | 4            | 1          |
| P4      | 5            | 4          |

### Gantt Chart for Non-Preemptive SJF:
```
| P1 | P3 | P2 | P4 |
0    7    8    12   16
```

### Average Waiting Time:
1. Calculate completion time (CT) for each process.
2. Calculate turnaround time (TAT) = CT - Arrival Time.
3. Calculate waiting time (WT) = TAT - Burst Time.
4. Average WT = (Sum of WT) / Number of Processes.

---

## 🚀 Conclusion
SJF is highly efficient for reducing waiting and turnaround times, but its practical use is limited by the need for accurate burst time predictions.
