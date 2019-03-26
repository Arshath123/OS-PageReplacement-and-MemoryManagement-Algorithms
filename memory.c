#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void worst_fit(int m[],int n,int p[],int k){
	int i,j,me[n],pr[k],aloc[k];
	for(i=0;i<n;i++)
		me[i] = m[i];
	for(i=0;i<k;i++)
		pr[i] = p[i];
	for(i=0;i<k;i++)
		aloc[i] = -1;
	int maxi,worst_index;
	for(i=0;i<k;i++){
		maxi = -1,worst_index = -1;
		for(j=0;j<n;j++){
			if((me[j]-p[i] >= maxi) && (me[j]-p[i] >= 0)){
				maxi = me[j]-p[i];
				worst_index = j;
			}
		}
		if(worst_index  != -1){
			aloc[i] = worst_index + 1;
			me[worst_index] -= p[i];
		}
	}
	for(i=0;i<k;i++){
		if(aloc[i] == -1){
			printf("Process %d is un-allocated\n",i+1);
		}
		else{
			printf("Process %d is allocated to %d th block\n",i+1,m[aloc[i]-1]);
		}
	}
}

void best_fit(int m[],int n,int p[],int k){
	int i,j,me[n],pr[k],aloc[k];
	for(i=0;i<n;i++)
		me[i] = m[i];
	for(i=0;i<k;i++)
		pr[i] = p[i];
	for(i=0;i<k;i++)
		aloc[i] = -1;
	int mini,best_index;
	for(i=0;i<k;i++){
		mini = INT_MAX,best_index = -1;
		for(j=0;j<n;j++){
			if((me[j]-p[i] <= mini) && (me[j]-p[i] >= 0)){
				mini = me[j]-p[i];
				best_index = j;
			}
		}
		if(best_index != -1){
			aloc[i] = best_index+1;
			me[best_index] -= p[i];
		}
	}
	for(i=0;i<k;i++){
		if(aloc[i] == -1){
			printf("Process %d is un-allocated\n",i+1);
		}
		else{
			printf("Process %d is allocated to %dkb\n",i+1,m[aloc[i]-1]);
		}
	}
}

void first_fit(int m[],int n,int p[],int k){
	int i,j,me[n],pr[k],aloc[k];
	for(i=0;i<n;i++)
		me[i] = m[i];
	for(i=0;i<k;i++)
		aloc[i] = -1;
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			if(p[i] <= me[j]){
				aloc[i] = j+1;
				me[j] -= p[i];
				break;
			}
		}
	}
	for(i=0;i<k;i++){
		if(aloc[i] == -1){
			printf("Process %d is un-allocated\n",i+1);
		}
		else{
			printf("Process %d is allocated to %d th block\n",i+1,m[aloc[i]-1]);
		}
	}
}
int main(){
	int n,i,k;

	printf("\nEnter the number of memory blocks\n");
	scanf("%d",&n);

	int m[n];
	printf("\nEnter the memory partitions\n");
	for(i=0;i<n;i++)
		scanf("%d",&m[i]);

	printf("\nEnter the number of processes\n");
	scanf("%d",&k);

	int p[k];
	printf("\nEnter the memory required by processes\n");
	for(i=0;i<k;i++)
		scanf("%d",&p[i]);

	printf("\n..........Memory Partition.......\n");
	for(i=0;i<n;i++)
		printf("%d\t",m[i]);
	printf("\n");

	printf("\nEnter 1.First Fit\n2.Best Fit\n3.Worst Fit\n");
	int ch;
	scanf("%d",&ch);
	while(1){
		switch(ch){
			case 1:
				first_fit(m,n,p,k);
				break;
			case 2:
				best_fit(m,n,p,k);
				break;
			case 3:
				worst_fit(m,n,p,k);
				break;
			case 4: exit(0);
		}
		printf("\nEnter 1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit\n");
		scanf("%d",&ch);
	}
	return 0;
}
