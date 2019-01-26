#include"stackImpl_Header.h"
#include<string.h>

/*
NOTE :- THIS PROGRAM USES stackImpl_Header.h file which contains the implementation for all stack functions
NOTE :- IN PROGRM  ONLY "+,-,*,/" OPERATORS ARE CONSIDERED
NOTE :- UNCOMMENT THE PRINT STATEMENT IN PUSH AND POP FUNCTION UNDER HEADER FILE TO BETTER UNDERSTAND HOW STACK IS BEING USED 
*/

#define MAX_SIZE 100
int *stackArr;
int top;

int main()
{
	char *str,c,ch,*stackArr;
	char operator[]={'+','-','*','/'};
  	int i = 0, j = 0 , k=0;
	int size;
  	str = (char*)malloc(sizeof(char)*MAX_SIZE);
	stackArr = malloc(sizeof(int)*MAX_SIZE);
	top = -1;

	printf("Enter the string");
	
	    while (c != '\n') 
	    {

		    c = getc(stdin);

		    str[i] = c;

		    i++;
	  	}

	str[i] = '\0'; // at the end append null character to mark end of string

	printf("\nThe entered string is : %s", str);
	for(k=0;k<i-1;k++)
	{
		if(str[k] != '+' && str[k] != '-' && str[k] != '*' && str[k] != '/')
		{
			printf(" %c ",str[k]);
		}
		if(str[k] == '+' || str[k] == '-' || str[k] == '*' || str[k] == '/')
		{
			if(top == -1)
			{
				top = push(stackArr,top,str[k]);
			}
			else
			{
				if(str[k] == '+' || str[k] == '-')
				{
					for(j=top;j>=0;j--)
					{
						printf(" %c ",getTop(stackArr,top));
						top = pop(stackArr,top);
					}
					top = push(stackArr,top,str[k]);	
				}

				else if (str[k] == '*' || str[k] == '/')
				{
					for(j=top;j>=0;j--)
					{
						if (stackArr[j] == '+' || stackArr[j] == '-')
						{
							top = push(stackArr,top,str[k]);
							break;
						}
						else
						{
							printf(" %c ",getTop(stackArr,top));
							top = pop(stackArr,top);	
						}
						
					}
				}

				else
				{

				}
			}
		}
	}

	printStack(stackArr,top);

	return 0;
}