#include <stdio.h>

typedef struct process {
	int number;
	int burst_time;
	int remaining_time;
	int waiting_time;
	int turnaround_time;
	int completion_time;
}process;

process queue[100];
int n;

int check () {
	int i;
	for(i=0;i<n;i++) {
		if(queue[i].remaining_time != 0) {
			return 1;
		}
	}
	return 0;
}

void incr_waiting_time (int key, int count) {
	int i;
	for(i=0;i<n;i++) {
		if(queue[i].remaining_time > 0) {
			queue[i].waiting_time += count;
		}
	}
	queue[key].waiting_time -= count;
}

void main () {
	int quantum;
	int i;
	int flag = 0;
	double avg_w = 0;
	double avg_t = 0;
	printf("Enter time quantum : \n");
	scanf("%d",&quantum);
	printf("Enter the number of processes : \n");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		queue[i].number = i;
		printf("Enter burst time : \n");
		scanf("%d",&queue[i].burst_time);
		queue[i].remaining_time = queue[i].burst_time;
		queue[i].waiting_time;
	}
	i = 0;
	while(check()) {
		if (queue[i].remaining_time == 0) {
			i = (i+1)%n;
			continue;
		}
		if(queue[i].remaining_time > quantum) {
			printf("Process : %d\n",i );
			queue[i].remaining_time -= quantum;
			//printf("remaining_time : %d\n",queue[i].remaining_time);
			incr_waiting_time (i,quantum);
			i = (i+1)%n;
			continue;
		} 
		if (queue[i].remaining_time <= quantum) {
			printf("Process : %d\n",i );
			incr_waiting_time(i,queue[i].remaining_time);
			queue[i].remaining_time = 0;
			//printf("remaining_time : %d\n",queue[i].remaining_time);
			i = (i+1)%n;
			continue;	
		}
	}
	for(i=0;i<n;i++) {
		printf("Process : %d\n",i);
		printf("waiting_time : %d\n", queue[i].waiting_time);
		queue[i].turnaround_time = queue[i].waiting_time + queue[i].burst_time;
		printf("turnaround_time : %d\n", queue[i].turnaround_time);
		avg_t += queue[i].turnaround_time;
		avg_w += queue[i].waiting_time;
	}
	printf("avg waiting_time : %lf\n",(avg_w / n) );
	printf("avg turnaround_time : %lf\n",(avg_t / n) );
}