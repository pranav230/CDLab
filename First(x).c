/*
    Input Format for Productions Enter:  A=b23A
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 10

void FIRST(char c, int q1, int q2)
{
	int j;       
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
                    //first[n++] = '#'; 
                    printf("\nElement not found");
                    first[count++]=' ';
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
            }
            else 
            { 
                // Recursion to calculate First of New Non-Terminal we encounter at the beginning 
                FIRST(productions[j][2], j, 3); 
            } 
        } 
    }
}

int n,count=0;
char productions[MAX][MAX],first[MAX];

int main(){
    int choice;
    char ch,c;
    printf("Enter total number of productions");
    scanf("%d",&n);
    printf("Enter %d productions:\n",n);
    for(int i=0;i<n;i++){
        printf("Production %d = ",i+1);
        scanf("%s%c",productions[i],&ch);
    }
    do
	{
		n=0;
		printf("Element :");
		scanf("%c",&c);
		FIRST(c,0,0);
		printf("\n FIRST(%c)= { ",c);
		for(int i=0;i<n;i++)
			printf("%c ",first[i]);
		printf("}\n");
		printf("press 1 to continue : ");
		scanf("%d%c",&choice,&ch);
	}
	while(choice==1);
    return 0;
}