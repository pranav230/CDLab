#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct bankers{
	int allocation[3];
	int max[3];
	int need[3];
	int available[3];
};

typedef struct bankers banker;

void print(banker p[],int n){
	printf("Process\t Allocation\t MaxNeed\tNeed\t Available\n");
	printf("\t    A B C\t  A B C\t\tA B C \t   A B C\n");
	for(int i=0;i<n;i++){
		printf("P%d\t    %d %d %d\t  %d %d %d\t\t%d %d %d \t   %d %d %d\n",i+1,p[i].allocation[0],p[i].allocation[1],p[i].allocation[2],p[i].max[0],p[i].max[1],p[i].max[2],p[i].need[0],p[i].need[1],p[i].need[2],p[i].available[0],p[i].available[1],p[i].available[2]);
	}
}

int main(){
	int n,maxA,maxB,maxC,j;
	printf("Enter thr number of processes:");
	scanf("%d",&n);
	banker p[n];
	bool finish[n];
	int sequence[n];
	
	//taking input
	printf("Enter the total number of resources\n");
	scanf("%d%d%d",&maxA,&maxB,&maxC);
	
	for(int i=0;i<n;i++){
		printf("Enter the information for %d process\n",i+1);
		printf("Enter Allocation resources\n");
		scanf("%d%d%d",&p[i].allocation[0],&p[i].allocation[1],&p[i].allocation[2]);
		printf("Enter Maximum Need\n");
		scanf("%d%d%d",&p[i].max[0],&p[i].max[1],&p[i].max[2]);
		p[i].available[0]=0;
		p[i].available[1]=0;
		p[i].available[2]=0;
		
		//calculating total allocated resources for A,B and C
		maxA-=p[i].allocation[0];
		maxB-=p[i].allocation[1];
		maxC-=p[i].allocation[2];
		finish[i]=false;
	}

	//Computing Need matrix
	for(int i=0;i<n;i++){
		p[i].need[0]=p[i].max[0]-p[i].allocation[0];
		p[i].need[1]=p[i].max[1]-p[i].allocation[1];
		p[i].need[2]=p[i].max[2]-p[i].allocation[2];
	}
	
	//printf("%d %d %d \n",maxA,maxB,maxC);
	
	print(p,n);
	
	//Main Process starts here
	for(int i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(finish[j]==false && maxA>=p[j].need[0] && maxB>=p[j].need[1] && maxC>=p[j].need[2]){
				finish[j]=true;
				break;
			}
		}
		if(j==n){
			printf("Deadlock is confirm to happen\n");
			exit(0);
		}
		sequence[i]=j+1;
		p[i].available[0]=maxA;
		p[i].available[1]=maxB;
		p[i].available[2]=maxC;
		maxA+=p[j].allocation[0];
		maxB+=p[j].allocation[1];
		maxC+=p[j].allocation[2];
	}	

	print(p,n);
		
	printf("The safe sequence is \n");
	for(int i=0;i<n;i++){
		printf("%d ",sequence[i]);
	}
	printf("\n");
	return 0;
}
