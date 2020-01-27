#include<stdio.h>
#include<stdlib.h>

void rollback(int tempb[],int blocks[],int n){
    for(int i=0;i<n;i++){
        blocks[i]=tempb[i];
    }
}

int main(){ 
    //input
    int np;
    printf("Enter the number of processes:");
    scanf("%d",&np);
    int process[np];
    printf("Enter the processes size:\n");
    for(int i=0;i<np;i++){
        scanf("%d",&process[i]);
    }    

    int nb;
    printf("Enter the number of blocks : ");
    scanf("%d",&nb);
    int blocks[nb],tempb[nb];
    printf("Enter the blocks size:\n");
    for(int i=0;i<nb;i++){
        scanf("%d",&blocks[i]);
        tempb[i]=blocks[i];
    }   

    int choice; 

    while(1){
        printf("1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    for(int i=0;i<np;i++){
                        int j;
                        for(j=0;j<nb;j++){
                            if(process[i] <= blocks[j]){
                                break;
                            }
                        }
                        if(j!=nb){
                            blocks[j]-=process[i];
                            printf("Process %d in Block %d\n",i+1,j+1);
                        }
                        else{
                            printf("Can't allocate memory after this\n");
                            break;
                        }
                    }                    
                    rollback(tempb,blocks,nb);
                    break;
            case 2:
                    for(int i=0;i<np;i++){
                        int best=-1;
                        for(int j=0;j<nb;j++){
                            if( ( process[i] <= blocks[j] ) && ( blocks[j] < blocks[best] || best == -1 ))
                                best=j;
                        }
                        if(best == -1){
                            printf("Can't allocate memory after this\n");
                            break;
                        } else{
                            blocks[best] -= process[i];
                            printf("Process %d in Block %d\n",i+1,best+1);
                        }
                    }
                    rollback(tempb,blocks,nb);
                    break;
            case 3:
                    for(int i=0;i<np;i++){
                        int high = 0;
                        for(int j=1;j<nb;j++){
                            if(blocks[j] > blocks[high])
                                high=j;
                        }
                        if(process[i] <= blocks[high] ){
                            blocks[high] -= process[i];
                            printf("Process %d in Block %d\n",i+1,high+1);
                        } else{
                            printf("Can't allocate memory after this\n");
                            break;
                        }
                    }
                    rollback(tempb,blocks,nb);
                    break;
            case 4:
                    exit(0);
            default:
                    printf("You Entered the wrong choice\n");
        }
    }
    return 0;
}