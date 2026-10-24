#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a process and its scheduling metrics 
typedef struct { 
    int pid; 
    int arrival_time; 
    int burst_time; 
    int completion_time; 
    int turnaround_time; 
    int waiting_time; 
    int response_time; 
    bool completed; 
} Process;

// Function prototypes 
void print_gantt_chart(Process execution_order[], int count, int start_times[], int end_times[]); 
void print_results(Process procs[], int n);
void simulate_fcfs(Process input_procs[], int n); 
void simulate_sjf(Process input_procs[], int n);

// Helper function to sort processes by arrival time (and PID as tie-breaker) 
void sort_by_arrival_time(Process procs[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (procs[j].arrival_time > procs[j + 1].arrival_time 
            || (procs[j].arrival_time == procs[j + 1].arrival_time 
            && procs[j].pid > procs[j + 1].pid)) { 
                Process temp = procs[j];
                procs[j] = procs[j + 1]; 
                procs[j + 1] = temp; 
            } 
        } 
    } 
}

// Function to print the Gantt chart along with time intervals 
void print_gantt_chart(Process execution_order[], int count, int start_times[], int end_times[]) { 
    printf("Gantt Chart: "); 
    for (int i = 0; i < count; i++) { 
        printf("| P%d ", execution_order[i].pid); 
    } 
    printf("|\n"); 
    printf("Timeline: "); 
    if (count > 0) { 
        printf("%-8d", start_times[0]); 
        for (int i = 0; i < count; i++) { 
            printf("%-8d", end_times[i]); 
        } 
    } 
    printf("\n"); 
}

// Function to print process metrics and calculate averages 
void print_results(Process procs[], int n) { 
    double total_wt = 0; 
    double total_tat = 0; 
    double total_rt = 0; 
    printf("\n%-8s %-8s %-8s %-8s %-8s %-8s\n", "PID", "AT", "BT", "WT", "TAT", "RT"); 
    for (int i = 0; i < n; i++) { 
        printf("%-8d %-8d %-8d %-8d %-8d %-8d\n", procs[i].pid, procs[i].arrival_time, 
        procs[i].burst_time, procs[i].waiting_time, procs[i].turnaround_time, procs[i].response_time); 
        total_wt += procs[i].waiting_time; 
        total_tat += procs[i].turnaround_time; total_rt += procs[i].response_time; 
    } 
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n); 
    printf("Average Turnaround Time: %.2f\n", total_tat / n); 
    printf("Average Response Time: %.2f\n", total_rt / n); 
}

// First Come First Served (FCFS) Scheduling Algorithm 
void simulate_fcfs(Process input_procs[], int n) { 
    printf("\n=== First Come First Served (FCFS) ===\n"); 
    Process procs[n]; 
    for (int i = 0; i < n; i++) { 
        procs[i] = input_procs[i]; 
    } 
    sort_by_arrival_time(procs, n); 
    Process execution_order[n]; 
    int start_times[n]; 
    int end_times[n]; 
    int current_time = 0; 
    for (int i = 0; i < n; i++) { 
        if (current_time < procs[i].arrival_time) { 
            current_time = procs[i].arrival_time; // Handles CPU Idle gaps 
        } 
        int start_time = current_time; 
        procs[i].response_time = start_time - procs[i].arrival_time; 
        procs[i].completion_time = start_time + procs[i].burst_time; 
        procs[i].turnaround_time = procs[i].completion_time - procs[i].arrival_time; 
        procs[i].waiting_time = procs[i].turnaround_time - procs[i].burst_time; 
        current_time = procs[i].completion_time; 
        execution_order[i] = procs[i]; 
        start_times[i] = start_time; 
        end_times[i] = current_time; 
    } 
    print_gantt_chart(execution_order, n, start_times, end_times); 
    print_results(procs, n); 
}

// Non-preemptive Shortest Job First (SJF) Scheduling Algorithm 
void simulate_sjf(Process input_procs[], int n) { 
    printf("\n=== Shortest Job First (SJF) ===\n"); 
    Process procs[n]; 
    for (int i = 0; i < n; i++) { 
        procs[i] = input_procs[i]; 
        procs[i].completed = false; 
    } 
    Process execution_order[n]; 
    int start_times[n]; 
    int end_times[n]; 
    int current_time = 0; 
    int completed_count = 0; 
    while (completed_count < n) { 
        int idx = -1; 
        int min_burst = 1e9; 
        // Find the process with shortest burst time among those already arrived 
        for (int i = 0; i < n; i++) { 
            if (!procs[i].completed && procs[i].arrival_time <= current_time) { 
                if (procs[i].burst_time < min_burst) { 
                    min_burst = procs[i].burst_time; 
                    idx = i; 
                } 
                else if (procs[i].burst_time == min_burst) { 
                    // Tie-breaker: earlier arrival time, then lower PID 
                    if (procs[i].arrival_time < procs[idx].arrival_time 
                    || (procs[i].arrival_time == procs[idx].arrival_time 
                    && procs[i].pid < procs[idx].pid)) { 
                        idx = i; 
                    } 
                } 
            } 
        } 
        // Handle CPU Idle time if no process has arrived yet 
        if (idx == -1) { 
            int earliest_arrival = 1e9; 
            for (int i = 0; i < n; i++) { 
                if (!procs[i].completed && procs[i].arrival_time < earliest_arrival) { 
                    earliest_arrival = procs[i].arrival_time; 
                } 
            } 
            current_time = earliest_arrival; 
            continue; 
        } 
        // Execute selected process 
        int start_time = current_time; 
        procs[idx].response_time = start_time - procs[idx].arrival_time; 
        procs[idx].completion_time = start_time + procs[idx].burst_time; 
        procs[idx].turnaround_time = procs[idx].completion_time - procs[idx].arrival_time; 
        procs[idx].waiting_time = procs[idx].turnaround_time - procs[idx].burst_time; 
        procs[idx].completed = true; 
        current_time = procs[idx].completion_time; 
        execution_order[completed_count] = procs[idx]; 
        start_times[completed_count] = start_time; 
        end_times[completed_count] = current_time; 
        completed_count++; 
    } 
    print_gantt_chart(execution_order, n, start_times, end_times); 
    print_results(execution_order, n); 
}

int main() { 
    int n;  
    printf("Enter the number of processes: "); 
    if (scanf("%d", &n) != 1 || n <= 0) { 
        printf("Invalid number of processes.\n"); 
        return 1; 
    } 
    Process procs[n]; 
    for (int i = 0; i < n; i++) { 
        procs[i].pid = i + 1; 
        printf("Enter the arrival time and burst time for process %d: ", i + 1); 
        if (scanf("%d %d", &procs[i].arrival_time, &procs[i].burst_time) != 2 
        || procs[i].arrival_time < 0 || procs[i].burst_time <= 0) { 
            printf("Invalid arrival or burst time entered.\n"); 
            return 1; 
        } 
    } 
    simulate_fcfs(procs, n); 
    simulate_sjf(procs, n); 
    
    return 0; 
}

