#include<stdio.h>
#include<stdlib.h>

int push(int *arr,int top,int val)
{
	top++;
	arr[top] = val;
	return top;
}

int pop(int *arr,int top)
{
	top--;
	return top;
}

void printStack(int *arr,int top)
{
	int i; 
	for(i=top;i>=0;i--)
	{
		printf("stack [%d] is %d",(top-i),arr[i]);
		printf("\n");
	}
}

void getTop(int *arr,int top)
{
	printf("Top of the stack is %d",arr[top]);
	printf("\n");
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

int main()
{	
	int top=-1,n;
	int *arr;
	printf("Enter size of Array");
	scanf("%d",&n);

	arr = calloc(sizeof(int),n);

	isEmpty(top);

	top = push(arr,top,10);
	top = push(arr,top,20);
	
	printf("before popoing .....\n");
	printStack(arr,top);

	top = pop(arr,top);

	printf("after popoing .....\n");

	printStack(arr,top);
	
	printf("pushing two more elements\n");

	top = push(arr,top,30);
	top = push(arr,top,20);

	printStack(arr,top);

	getTop(arr,top);

	isEmpty(top);

	return 0;
}
