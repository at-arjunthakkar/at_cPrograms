#include<stdio.h>
#include<stdlib.h>

int front,tail;
int qArr[100];

void enQ(int data) //insert at tail
{
	if(tail==-1) //if Q is empty
	{
		front++; 
	}
	qArr[++tail] = data;
}

void dQ() // delete from front
{
	if(tail==-1) //if Q is empty
	{
		printf("Queue is empty\n");
		return;
	}
	else
		front++;
}

int peek()
{
	printf("\nPeek element of Queue is %d \n",qArr[front]);
	return qArr[front];
}

void dispQueueEle()
{
	int i;
	printf("\n<----- Displaying Queue ---------------->\n");
	for(i=front;i<=tail;i++)
	{
		printf("%d\n",qArr[i]);
	}
}

int main()
{
	front = -1;
	tail = -1;
	enQ(10);
	enQ(20);
	enQ(30);
	dispQueueEle();
	dQ();
	dispQueueEle();
	enQ(40);
	dQ();
	dispQueueEle();
	peek();
	return 0;
}