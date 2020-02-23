# include<stdio.h>
# include<stdlib.h>

# define MAX 10

//structure of a process
struct process
{
	int arrival;
	int burst;
	int wait;
	int turn; //turnaround time
	int proc;
	int priority;
	int rem; //remaining time
};

//comparators for sorting

int cmp_at(const void *a,const void *b){
    process *temp1=(info *)a;
    process *temp2=(info *)b;
    return (temp1->priority > temp2->priority);
}

int cmp_proc(const void *a,const void *b){
    process *temp1=(info *)a;
    process *temp2=(info *)b;
    return (temp1->proc > temp2->proc);
}

//comparators finished

int main()
{
	struct process p[MAX];
	double total_wait=0, total_turn=0;
	int i, j, k, num;
	
	printf("\nEnter number of processes:");
	scanf("%d", &num);
	
	for(i=0; i<num;i++)
	{
		printf("\nProcess %d",i+1);
		printf("\n\tArrival time:");
		scanf("%d", &p[i].arrival);
		printf("\tBurst time  :");
		scanf("%d", &p[i].burst);
		printf("\tPriority    :");
		scanf("%d",&p[i].priority);
		p[i].proc = i+1;
		p[i].wait=0;
		p[i].rem = p[i].burst; //initialising remaining time with burst time
	}
	
	qsort(p,num,sizeof(process),cmp_p);
	
	for(i=0,k=0; k<num; i++) //i counter counts the seconds passed
	//each iteration means one second time 
	{						 
		for(j=0; j<num; j++) 
		{
			if(p[j].arrival <= i && p[j].rem != 0)
			{
				p[j].rem--;
				if(p[j].rem == 0)
				{
					k++;
					p[j].wait = i+1 - (p[j].burst + p[j].arrival);
					p[j].turn = p[j].wait + p[j].burst;
				}
				//break after every second
				break;
			}
		}
	}
	
	qsort(p,num,sizeof(process),cmp_proc);
	
	for(i=0;i<num;i++)
	{
		printf("\nWaiting time of process%d = %d", i+1, p[i].wait );
		total_wait += p[i].wait;
	}
	
	printf("\nAverage waiting time = %lf ms\n",total_wait/num );
	
	for(i=0;i<num;i++)
	{
		printf("\nTurn around time of process%d = %d", i+1, p[i].turn );
		total_turn += p[i].turn;
	}
	
	printf("\nAverage turn around time = %lf ms\n", total_turn/num );
	return 0;
}