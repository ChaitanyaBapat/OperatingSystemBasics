#include <stdio.h>

typedef struct process{
	int process_number, arrival_time, burst_time, waiting_time, turnaround_time, completion_time;
}process;

void main () {

	int n;
	int i;
	int min;
	int j;
	process queue[100];
	double avg_wait = 0.0, avg_turn = 0.0;
	printf("FCFS\n");
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	for(i = 0; i < n; i++ ) {
		queue[i].process_number = i;
		printf("Process Number : %d\n",i );
		printf("Enter Arrival Time : ");
		scanf("%d",&queue[i].arrival_time);
		printf("Enter burst time : ");
		scanf("%d",&queue[i].burst_time);
	}
	process temp;
	for(i=0;i<n-1;i++) {
		min = i;
		for(j=i+1;j<n;j++) {
			if(queue[j].arrival_time < queue[min].arrival_time) {
				min = j;
			}
		}
		if(min != i) {
			temp = queue[min];
			while(min > i) {
				queue[min] = queue[min-1];
				min--;
			} 			
			queue[i] = temp;
		}
 	}
 	for(i=0;i<n;i++) {
 		printf("%d\n",queue[i].process_number	 );
 	}
 	//add table here

 	queue[0].waiting_time = 0;
 	queue[0].completion_time = queue[0].arrival_time + queue[0].burst_time;
 	queue[0].turnaround_time = queue[0].completion_time - queue[0].arrival_time;
 	printf("process_number : %d\n",queue[0].process_number);
	printf("arrival_time : %d\n",queue[0].arrival_time);
	printf("burst_time : %d\n",queue[0].burst_time);
	printf("waiting_time : %d\n",queue[0].waiting_time);
	printf("completion_time : %d\n",queue[0].completion_time);
	printf("turnaround_time : %d\n",queue[0].turnaround_time);
	avg_wait += queue[0].waiting_time;
	avg_turn += queue[0].turnaround_time;
	printf("\n");
 	for(i=1;i<n;i++) {
 		queue[i].completion_time = queue[i-1].completion_time + queue[i].burst_time;
 		queue[i].turnaround_time = queue[i].completion_time - queue[i].arrival_time;
 		queue[i].waiting_time = queue[i-1].completion_time - queue[i].arrival_time;
 		printf("process_number : %d\n",queue[i].process_number);
 		printf("arrival_time : %d\n",queue[i].arrival_time);
 		printf("burst_time : %d\n",queue[i].burst_time);
 		printf("waiting_time : %d\n",queue[i].waiting_time);
 		printf("completion_time : %d\n",queue[i].completion_time);
 		printf("turnaround_time : %d\n",queue[i].turnaround_time);
 		printf("\n");
 		avg_wait += queue[i].waiting_time;
		avg_turn += queue[i].turnaround_time;
 	}
 	printf("Avg waiting_time = %lf\n",avg_wait / n );
 	printf("Avg turnaround_time = %lf\n",avg_turn / n );
}