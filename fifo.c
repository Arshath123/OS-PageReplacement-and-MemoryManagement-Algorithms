#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,*p,*f,m,i,j,k,counter = 0,page_fault = 0;

	printf("\nEnter the number of pages\n");
	scanf("%d",&n);
	p = (int *)malloc(n*sizeof(int));

	printf("\nEnter the pages\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);

	printf("\nEnter the frame size\n");
	scanf("%d",&m);
	f = (int *)malloc(m*sizeof(int));

	for(int i=0;i<m;i++)
		f[i] = -1;

	printf("\n...The pages are...\n");

	for(i=0;i<n;i++){

		int flag = 0;

		for(j=0;j<m;j++){
			if(p[i] == f[j]){
				flag  = 1;
				break;
			}
		}

		if(flag==0){
			f[counter++] = p[i];
			page_fault++;
		}

		for(k=0;k<m && f[k] != -1;k++){
			printf("%d ",f[k]);
		}

		printf("\nThe page fault is %d\n",page_fault);
		if(counter == m)
			counter = 0;
	}
	return 0;
}
