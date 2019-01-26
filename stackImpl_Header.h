#include<stdio.h>
#include<stdlib.h>

int push(char *arr,int top,char val)
{
	//printf("\npush called\n");
	top++;
	arr[top] = val;
	return top;
}

int pop(char *arr,int top)
{
	//printf("\npop called\n");
	top--;
	return top;
}

void printStack(char *arr,int top)
{
	int i; 
	//printf("<!-------printing stack------>\n");
	for(i=top;i>=0;i--)
	{
		printf(" %c ",arr[i]);
		//printf("\n");
	}
}

char getTop(char *arr,int top)
{
	//printf(" %c ",arr[top]);
	return arr[top];
}

int isEmpty(int top)
{
	if(top == -1)
	{
		printf("stack is empty\n");	
		return 0;	
	}	
	else
	{
		printf("stack is not empty\n");
		return -1;
	}
		
}