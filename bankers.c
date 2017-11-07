#include <stdio.h>

int finished[100];
int allocation[100][100], max[100][100],need[100][100],available[100];
int n,r;
int check () {
	int i;
	for(i=0;i<n;i++) {
		if(finished[i] == 0) {
			return 1;
		}
	}
	return 0;
}

int isNeedless(int row) {
	int i,j;
	i = row;
	for(j=0;j<r;j++) {
		if(need[row][j] > available[j]) {
			return 0;
		}
	}
	return 1;
}

void main () {
	int i,j,k,row;
	printf("Enter no. of processes : ");
	scanf("%d",&n);
	printf("Enter number of resources : ");
	scanf("%d",&r);
	printf("Enter allocation matrix\n");
	for(i=0;i<n;i++) {
		printf("Enter resources of process %d\n",i);
		for(j=0;j<r;j++) {
			printf("Enter resources %d : ",j);
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter maximum matrix\n");
	for(i=0;i<n;i++) {
		printf("Enter resources of process %d\n",i);
		for(j=0;j<r;j++) {
			printf("Enter resources %d : ",j);
			scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<n;i++) {
		for(j=0;j<r;j++) {
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	printf("Enter available array :\n");
	for(i=0;i<r;i++) {
		printf("Resource %d : ",i );
		scanf("%d",&available[i]);
	}
	//clear finished array
	for(i=0;i<n;i++) {
		finished[i] = 0;
	}
	row = 0;
	printf("Safe sequence : ");
	while (check()) {
		//check need <= available
		if(finished[row] == 0) {
			if(isNeedless(row)) {
			finished[row] = 1;
				for(i=0;i<r;i++) {
					available[i] = available[i] + allocation[row][i];
				}
				printf("%d ",row);
			}
		}
		row = (row+1)%n;
	}
	printf("\n");
}