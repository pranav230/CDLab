#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

int main()
{
	char str[MAX];
	int i = 0,state = 0;
	
	printf("\nEnter the string:");
	gets(str);
	
	char ch;
	
	while(str[i] != '\0')
	{
		switch(state)
		{
			case 0:
                    ch = str[i++];
					
                    if(ch == 'a')
						state = 1;
					else if(ch == 'b')
						state = 5;
					else
						state = 6;
					break;
					
			case 1:
                    ch = str[i++];
					
                    if(ch == 'a')
						state = 4;
					else if(ch == 'b')
						state = 2;
					else
						state = 6;
					break;
					
			case 2:
                    ch = str[i++];
					
                    if(ch == 'a')
						state = 6;
					else if(ch == 'b')
						state = 3;
					else
						state = 6;
					break;
					
			case 3:
                    ch = str[i++];
					
                    if(ch == 'b')
						state = 5;
					else
						state = 6;
					break;
					
			case 4:
                    ch = str[i++];
					
                    if(ch == 'a')
						state = 4;
					else if(ch == 'b')
						state = 5;
					else
						state = 6;
					break;
					
			case 5:
                    ch = str[i++];
					
                    if(ch == 'b')
						state = 5;
					else
						state = 6;
					break;
					
			case 6:
                    printf("Invalid String");
					exit(0);
		}
	}

	if(state == 0 || state == 1 || state == 4)
		printf("\n%s is accepted under a*\n",str);
	else if(state == 2 || state == 5)
		printf("\n %s Accepted under a*b+\n",str);
	else if(state == 3)
		printf("%s Accepted under abb\n",str);
	else
		printf("\nNo match has occured\n");
	
    return 0;
}