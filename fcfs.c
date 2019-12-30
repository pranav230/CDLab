#include<stdio.h>

struct pInfo{
    int no;
    double at;
    double bt;
    double tat;
    double wt;
};

typedef struct pInfo info;

int cmp_at(const void *a,const void *b){
    info *temp1=(info *)a;
    info *temp2=(info *)b;
    return (temp1->at > temp2->at);
}

int cmp_pno(const void *a,const void *b){
    info *temp1=(info *)a;
    info *temp2=(info *)b;
    return (temp1->no > temp2->no);
}

int main(){
    int n,i,j;
    printf("Enter the number of proesses:");
    scanf("%d",&n);
    
    info process[10];
    //taking input
    for(i=0;i<n;i++){
        printf("Enter the info for process %d:\n",i+1);
        printf("Enter the process no:");
        scanf("%d",&process[i].no);
        printf("Arrival Time:");
        scanf("%lf",&process[i].at);
        printf("Burst Time:");
        scanf("%lf",&process[i].bt);
        process[i].tat=0;
        process[i].wt=0;
        printf("\n");
    }
    
    //sorting
    qsort(process,n,sizeof(struct pInfo),cmp_at);
    
    //printing after sorting
    printf("Process No \t Arrival time \t Burst Time \n");
    for(i=0;i<n;i++){
        printf("%6d \t %5.0lf \t %5.0lf\n",process[i].no,process[i].at,process[i].bt);
    }
    printf("\n\n");
    
    int totaltime=0;
    
    for(i=0;i<n;i++){
        if(totaltime < process[i].at){
            totaltime+=(process[i].at-totaltime);
        }
        totaltime+=process[i].bt;
        process[i].tat=totaltime-process[i].at;
        process[i].wt=process[i].tat-process[i].bt;
    }
    
    //sorting accordig to process no.
    qsort(process,n,sizeof(struct pInfo),cmp_pno);

    //printing the sorted arr
    printf("Process No \t Arrival time \t Burst Time \t Waiting time \t Turn Around Time \n");   
    for(i=0;i<n;i++){
        printf("%6d\t\t %5.0lf \t\t %5.0lf \t\t %5.0lf \t\t %9.0lf\n",process[i].no,process[i].at,process[i].bt,process[i].wt,process[i].tat);
    }    
    
    return 0;
}
