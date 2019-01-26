#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1; //assuming we have stack size 100
int push(char *arr,int top,char val)
{
	top++;
	arr[top] = val;
	return top;
}

int pop(char *arr,int top)
{
	top--;
	return top;
}

void printStack(char *arr,int top)
{
	int i; 
	for(i=0;i<top;i++)
	{
		printf("| %c |",arr[i]);
		printf("\n");
	}
}

char getTop(char *arr,int top)
{
	printf("Top of the stack is %c",arr[top]);
	printf("\n");
	return arr[top];
}

void isEmpty(int top)
{
	if(top == -1)
	{
		printf("stack is empty\n");		
	}	
	else
	{
		printf("stack is not empty\n");
	}
		
}

void expressionNotBalanced()
{
	printf("\nexpression is not balancedd\n");
	return;
}

void main()
{
	char *str,c,ch,*stackArr;
  	int i = 0, j = 1 , k=0;
	
  	str = (char*)malloc(sizeof(char)*100);
  	stackArr = (char*)malloc(sizeof(char)*100);
	printf("Enter the string");
	
	    while (c != '\n') {

	    c = getc(stdin);

	    str[i] = c;

	    i++;
	  }

	str[i] = '\0'; // at the end append null character to mark end of string

	printf("\nThe entered string is : %s", str);

	for(k=0;k<=sizeof(str)-1;k++)
	{
		//printf("inside first for");
		if(str[k] != ',')
		{	
			//printf("inside first if");
			if(str[k] == '{' || str[k] == '(' || str[k] == '[')
			{
				printf("%c",str[k]);
				top = push(stackArr,top,str[k]);		
			}
			if(str[k] == '}' )
			{
				printf("<---- inside { ------>\n");
				if(getTop(stackArr,top) == '{')
				{
					top = pop(stackArr,top);
				}
				else
				{
					expressionNotBalanced();
				}
			}
			if(str[k] == ')')
			{
				printf("<---- inside ) ------>\n");
				if(getTop(stackArr,top) == '(')
				{
					top = pop(stackArr,top);
				}
				else
				{
					expressionNotBalanced();
				}
			}
			if(str[k] == ']')
			{
				printf("<---- inside ] ------>\n");
				if(getTop(stackArr,top) == '[')
				{
					top = pop(stackArr,top);
				}
				else
				{
					expressionNotBalanced();
				}
			}
		}
	}
	printf("printing stack\n");

	
	getTop(stackArr,top);
	printStack(stackArr,top);

	if(top == -1)
	{
		printf("expression is balanced\n");
	}
	
	free(str); 
	
}
