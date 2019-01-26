#include<stdio.h>
#include<stdlib.h>

struct Node* head;

struct Node{
	int data;
	struct Node* nextNode; 
};

struct Node* getNewNode(int data)
{
	struct Node* temp =(struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	temp->nextNode = NULL;
	return temp;
}


void insertNodeAtBegining(int data)
{
	struct Node* temp;
	temp = getNewNode(data);
	if(head == NULL)
	{
		head = temp;
		return;
	}
	else
	{
		//printf("<---------------- Inserting if head not null --------------->\n");
		temp->nextNode = head;
		head = temp;
	}
}

void insertNodeAtEnd(int data)
{
	//printf("<---------------- insert at end LinkList--------------->\n");
	struct Node* temp,*temp2;
	temp = getNewNode(data);
	temp2 = head;
	while(temp2->nextNode != NULL)
	{
		temp2 = temp2->nextNode;
	}
	temp2->nextNode = temp;
}

void insertNodeAtNthPos(int data,int pos)
{
	//printf("<---------------- insert at nth position LinkList--------------->\n");
	struct Node* temp,*temp2,*temp1;
	int i;
	temp = getNewNode(data);
	temp2 = head;
	if(pos == 1)
	{
		insertNodeAtBegining(data);
		return;
	}
	for(i=0;i<pos-2;i++)
	{
		temp2 = temp2->nextNode;	
	}
	temp->nextNode = temp2->nextNode;
	temp2->nextNode = temp;

}

void delNodeFromBegining()
{
	struct Node* temp=head;
	if(head == NULL)
	{
		printf("Linklist is empty");
		return;
	}
	else
	{
		head = temp->nextNode;
		free(temp);
	}
}

void delNodeFromEnd()
{
	struct Node* temp,*temp2;
	temp2 = head;
	while(temp2->nextNode != NULL)
	{
		temp = temp2;
		temp2 = temp2->nextNode;
	}
	temp->nextNode = NULL;
	free(temp2);
}

void delNodeFromNthPos(int pos)
{
	struct Node* temp,*temp2,*temp1;
	int i;
	temp2 = head;
	if(pos == 1)
	{
		delNodeFromBegining();
		return;
	}
	for(i=0;i<pos-2;i++)
	{
		temp2 = temp2->nextNode;	
	}
	temp = temp2->nextNode;
	temp2->nextNode = temp->nextNode;
	free(temp);

}

void dispLinkList(struct Node* tempNode)
{
	//printf("<---------------- Dispaying LinkList--------------->\n");
	if(tempNode != NULL)
	{
		printf("%d\n",tempNode->data);
		dispLinkList(tempNode->nextNode);
	}
		

}

void disLinkListInReverse(struct Node* temp)
{
	//printf("<---------------- Dispaying LinkList in Reverse--------------->\n");
	if(temp != NULL)
	{
		disLinkListInReverse(temp->nextNode);
		printf("%d\n",temp->data);
	}
}

void dispLinkList_iterative()
{
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->nextNode;	
	}
}

void reverseLinkList()
{
	struct Node* temp=head;
	struct Node* next=head;
	struct Node* prev=NULL;
	while(next != NULL){
		next = temp->nextNode;
		temp->nextNode = prev;
		prev = temp;
		temp = next;
	}
	head = prev;

}

int main()
{
	head = NULL;
	insertNodeAtBegining(10);
	insertNodeAtBegining(20);
	insertNodeAtBegining(30);
	insertNodeAtBegining(40);

	printf("<---------------- Dispaying LinkList--------------->\n");
	dispLinkList(head);

	dispLinkList_iterative();

	printf("<---------------- Dispaying LinkList in Reverse--------------->\n");
	disLinkListInReverse(head);

	insertNodeAtEnd(50);
	printf("<---------------- Dispaying LinkList--------------->\n");
	dispLinkList(head);

	insertNodeAtNthPos(25,3);
	printf("<---------------- Dispaying LinkList--------------->\n");
	dispLinkList(head);
	
	reverseLinkList();
	printf("<---------------- Dispaying LinkList--------------->\n");
	dispLinkList(head);

	delNodeFromBegining();
	printf("<---------------- Dispaying LinkList--------------->\n");
	dispLinkList(head);

	delNodeFromEnd();
	printf("<---------------- Dispaying LinkList--------------->\n");
	dispLinkList(head);

	delNodeFromNthPos(2);
	printf("<---------------- Dispaying LinkList--------------->\n");
	dispLinkList(head);

	return 0;
}