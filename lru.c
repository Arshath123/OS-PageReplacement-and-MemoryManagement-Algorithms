#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
	int n,*p,*f,m,i,j,k,max_pos = -1,page_fault=0,replace,s,counter = 0;
	
	printf("\nEnter the number of pages\n");
	scanf("%d",&n);
	p = (int *)malloc(n*sizeof(int));
	
	printf("\nEnter the pages\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	
	printf("\nEnter the frame size\n");
	scanf("%d",&m);
	f = (int *)malloc(m*sizeof(int));

	for(i=0;i<m;i++)
		f[i] = -1;

	
	printf("\n...The Pages are...\n");
	for(i=0;i<n;i++){
		int flag = 0, max_pos = INT_MAX;
		for(s=0;s<m;s++)
		{
			if(p[i] == f[s])
			{
				flag =  1;
				break;
			}
		}
		if(flag)
			continue;
		else{ 
			if(counter<m){
				f[counter++] = p[i];
				page_fault++;
			}
			else{
				for(j=0;j<m;j++){
					int found = 1;
					for(k=i-1;k>=0;k--){
						if(f[j] == p[k]){
							found = 0;
							break;			
						}			
					}
					if(!found && k < max_pos){
						max_pos = k;
						replace = j;
					}
					if(found){
						replace = j;
						break;
					} 
				}
				f[replace] = p[i];
				page_fault++;
			}
			
		}
		for(k=0;k<m && f[k] != -1;k++){
			printf("%d ",f[k]);
		}
		printf("\nThe page fault is %d\n",page_fault);	
	}
	return 0;
}
