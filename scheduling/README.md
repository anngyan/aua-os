# Process Scheduling Simulator in C

A C-based Process Scheduling Simulator implementing two classic CPU scheduling algorithms under Linux:
1. **First Come First Served (FCFS)**
2. **Shortest Job First (SJF) — Non-Preemptive**

---

## Features

- **Process Representation**: Tracks Process ID (`pid`), Arrival Time (`AT`), Burst Time (`BT`), Completion Time (`CT`), Turnaround Time (`TAT`), Waiting Time (`WT`), and Response Time (`RT`).
- **Gantt Chart Visualization**: Prints a Gantt chart showing execution sequence and time boundaries.
- **Metrics Calculation**: Computes individual and average metrics for Waiting Time, Turnaround Time, and Response Time.
- **Edge Case Handling**: Manages non-zero arrival times, CPU idle gaps, and tie-breaking for processes with identical burst or arrival times.

---

## Formulae Used

- **Completion Time ($CT$)**: Time at which process finishes execution.
- **Turnaround Time ($TAT$)**: $TAT = CT - AT$
- **Waiting Time ($WT$)**: $WT = TAT - BT$
- **Response Time ($RT$)**: $RT = \text{Start Time} - AT$ (Equal to $WT$ for non-preemptive algorithms)

---

## Prerequisites & Compilation

Requirement: Linux terminal with `gcc` installed.

### Compilation

```bash
gcc scheduler.c
```

### Running the Simulator

```bash
./a.out
```

---

## Sample Execution

### Input 1

```text
Enter the number of processes: 4
Enter the arrival time and burst time for process 1: 0 8
Enter the arrival time and burst time for process 2: 1 4
Enter the arrival time and burst time for process 3: 2 9
Enter the arrival time and burst time for process 4: 3 5
```

### Output 1

```text
=== First Come First Served (FCFS) ===
Gantt Chart: |   P1   |   P2   |   P3   |   P4   |
Timeline:    0       8       12      21      26      

PID      AT       BT       WT       TAT      RT      
1        0        8        0        8        0       
2        1        4        7        11       7       
3        2        9        10       19       10      
4        3        5        18       23       18      

Average Waiting Time: 8.75
Average Turnaround Time: 15.25
Average Response Time: 8.75

=== Shortest Job First (SJF) ===
Gantt Chart: |   P1   |   P2   |   P4   |   P3   |
Timeline:    0       8       12      17      26      

PID      AT       BT       WT       TAT      RT      
1        0        8        0        8        0       
2        1        4        7        11       7       
4        3        5        9        14       9       
3        2        9        15       24       15      

Average Waiting Time: 7.75
Average Turnaround Time: 14.25
Average Response Time: 7.75
```

### Input 2

```text
Enter the number of processes: 4
Enter the arrival time and burst time for process 1: 1 3 
Enter the arrival time and burst time for process 2: 2 4
Enter the arrival time and burst time for process 3: 1 2
Enter the arrival time and burst time for process 4: 4 4
```

### Output 2

```text
=== First Come First Served (FCFS) ===
Gantt Chart: | P1 | P3 | P2 | P4 |
Timeline: 1       4       6       10      14      

PID      AT       BT       WT       TAT      RT      
1        1        3        0        3        0       
3        1        2        3        5        3       
2        2        4        4        8        4       
4        4        4        6        10       6       

Average Waiting Time: 3.25
Average Turnaround Time: 6.50
Average Response Time: 3.25

=== Shortest Job First (SJF) ===
Gantt Chart: | P3 | P1 | P2 | P4 |
Timeline: 1       3       6       10      14      

PID      AT       BT       WT       TAT      RT      
3        1        2        0        2        0       
1        1        3        2        5        2       
2        2        4        4        8        4       
4        4        4        6        10       6       

Average Waiting Time: 3.00
Average Turnaround Time: 6.25
Average Response Time: 3.00
```

---

## Structure

- `scheduler.c`: Main C implementation containing `Process` structure, FCFS and SJF scheduling algorithms, Gantt chart generation, and interactive user prompts.
- `README.md`: Compilation guide, formula explanations, and sample outputs.
