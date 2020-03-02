/*
    Input Format for Productions Enter:  A=b23A
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 10

int n,count=0;
char productions[MAX][MAX],first[MAX];

void FIRST(char c, int q1, int q2)
{
	int j;   
    count=0;    
    // The case where we encounter a Terminal 
    if(!(isupper(c)))
        first[count++] = c;
    for(j = 0; j < n; j++) 
    { 
		if(productions[j][0] == c) 
        { 
			if(productions[j][2] == '#') 
            { 
				if(productions[q1][q2] == '\0')
				{
                    first[n++] = '#'; 
                    printf("\nElement not found");
                    // first[count++]=' ';
				}
                else if(productions[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) 
                { 
                    // Recursion to calculate First of New 
                    // Non-Terminal we encounter after epsilon 
                    FIRST(productions[q1][q2], q1, (q2+1)); 
                } 
                else
                    first[count++] = '#'; 
			}
			else if(!isupper(productions[j][2])) 
            { 
                first[count++] = productions[j][2]; 
                printf("%c",productions[j][2]);
            }
            else 
            { 
                // Recursion to calculate First of New Non-Terminal we encounter at the beginning 
                FIRST(productions[j][2], j, 3); 
            }
        } 
    }
}

int main(){
    int choice;
    char ch,c;
    printf("Enter total number of productions : ");
    scanf("%d",&n);
    //Production input format is given above
    printf("Enter %d productions:\n",n);
    for(int i=0;i<n;i++){
        printf("Production %d \n",i+1);
        //ch is temporary variable which is used for avoidance of reading newline in the next iteration
        scanf("%s%c",productions[i],&ch);
    }

    do
	{
		printf("Element :");
		scanf("%c",&c);
		FIRST(c,0,0);
		printf("\n FIRST(%c)= { ",c);
		for(int i=0;i<count-1;i++)
			printf("%c,",first[i]);
        printf("%c",first[count-1]);
		printf("}\n");
		printf("press 1 to continue : ");
		scanf("%d%c",&choice,&ch);
	}
	while(choice==1);
    return 0;
}