#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node
{
	int element;
	int depth;
	struct node *left;
	struct node *right;
};

node *root = (node *)malloc(sizeof(node));
int n,line;
int flag=0;

void Insert(node *father,int number,int d)
{
	if(number>father->element)
	{
		if(father->right==NULL)
		{
			node *temp = (node *)malloc(sizeof(node));
			father->right=temp;
			temp->element=number;
			temp->depth=d;
			temp->left=NULL;
			temp->right=NULL;
		}
		else
		{
			Insert(father->right,number,d+1);
		}
	}
	if(number<father->element)
	{
		if(father->left==NULL)
		{
			node *temp = (node *)malloc(sizeof(node));
			father->left=temp;
			temp->element=number;
			temp->depth=d;
			temp->left=NULL;
			temp->right=NULL;
		}
		else
		{
			Insert(father->left,number,d+1);
		}
	}
}

void find(node *father)
{
	if(father->depth==line)
	{
		flag=1;
		cout<<father->element<<",";
		return;
	}
	if(father->left==NULL && father->right==NULL)
		return;
	if(father->left!=NULL)
		find(father->left);
	if(father->right!=NULL)
		find(father->right);
}

int main()
{
	int temp;
	char comma;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp>>comma;
		if(i==0)
		{
			root->element=temp;
			root->left=NULL;
			root->right=NULL;
			root->depth=1;
		}
		else
		{
			Insert(root,temp,2);
		}
	}
	cin>>line;
	find(root);
	if(flag==0)
		cout<<-1;
	return 0;
}
