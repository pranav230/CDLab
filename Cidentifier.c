//Criteria to choose a identifier : letter_(letter_/digit)*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 31

int main()
{
    char str[MAX];
    int i;
    printf("Enter the Identifier:");
    scanf("%[^\n]%*c", str);
    
    if(strlen(str) > MAX){
        printf("\nSize of Identifier Exceeded\n--Invalid Identifier--\n");
        return 0;
    }

    if(!isalpha(str[0])&&str[0]!='_')
    {
        printf("\n--Invalid Identifier--\n");
        return 0;
    }

    for(i=1;str[i]!='\0';i++)
    {
        if(!isalnum(str[i])&&str[i]!='_')
        {
            printf("\n--Invalid Identifier--\n");
            return 0;
        }
    }

    printf("\n--Valid Identifier--\n");
    return 0;
}