#include<stdio.h>
#include<stdlib.h>

struct treeNode{

	int data;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
	struct treeNode* parent;
};

struct treeNode* root;

struct treeNode* getNewNode(int data)
{
	printf("Adding %d\n",data);
	struct treeNode* temp =(struct treeNode*) malloc(sizeof(struct treeNode));
	temp->data = data;
	temp->parent = NULL;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	return temp;
} 

struct treeNode* insertNode(struct treeNode* Node,int data,struct treeNode* parent)
{
	struct treeNode* temp = Node;
	if(temp == NULL)
	{
		temp = getNewNode(data);
		temp->parent = parent;
		if(root == NULL)
		{
			root = temp;
			root->parent = root;
		}
			
	}
	else if(temp->data > data)
	{
		temp->leftChild = insertNode(temp->leftChild,data,temp);
	}
	else
	{
		temp->rightChild = insertNode(temp->rightChild,data,temp);
	}
	return temp;	
}

void Preorder(struct treeNode* node)
{
	if(node == NULL)
	{
		return;
	}
	printf("%d\n",node->data);
	Preorder(node->leftChild);
	Preorder(node->rightChild);
}

void Inorder(struct treeNode* node)
{
	if(node == NULL)
	{
		return;
	}
	Inorder(node->leftChild);
	printf("%d\n",node->data);
	Inorder(node->rightChild);
}

void Postorder(struct treeNode* node)
{
	if(node == NULL)
	{
		return;
	}
	Postorder(node->leftChild);
	Postorder(node->rightChild);
	printf("%d\n",node->data);
}

void findMin(struct treeNode* node)
{
	if(node->leftChild == NULL)
	{
		printf("\nMin is %d\n",node->data);
		return;
	}
	findMin(node->leftChild);
}

void findMax(struct treeNode* node)
{
	if(node->rightChild == NULL)
	{
		printf("\nMax is %d\n",node->data);
		return;
	}
	findMax(node->rightChild);
}

void printParentData(int data,struct treeNode* node)
{
	if (node == NULL)
		return;
	else if(node->data == data)
	{
		printf("\nParent value %d\n", node->parent->data);
		return;
	}
	else if(node->data > data)
	{
		printParentData(data,node->leftChild);
	}
	else
		printParentData(data,node->rightChild);
}

int max(int a , int b)
{
	if(a>= b)
		return a;
	else 
		return b;
}

int findHeight(struct treeNode* node)
{
	struct treeNode* temp = node;
	if(temp == NULL)
		return -1;
	else
		return (max(findHeight(temp->leftChild),findHeight(temp->rightChild))+1);
}
void main()
{
		root = NULL;
		insertNode(root,10,root);
		insertNode(root,20,root);
		insertNode(root,5,root);
		insertNode(root,7,root);
		insertNode(root,1,root);
		printf("******Preorder*********\n");
		Preorder(root);
		printf("******Inorder*********\n");
		Inorder(root);
		printf("******Postorder*********\n");
		Postorder(root);
		findMin(root);
		findMax(root);
		printf("Height of the tree is %d .",findHeight(root));
		printParentData(7,root);
}
