#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node
{
	int element;
	int depth;
	struct node *left;
	struct node *right;
};

node *root = (node *)malloc(sizeof(node));
int n,line,flag=0;
char a[10001];
int b[10001];

void Insert(node *father,int number,int d)
{
	if(number>father->element)
	{
		if(father->right==NULL)
		{
			//cout<<father->element<<" ";
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
			//cout<<father->element<<" ";
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

	if(father->left==NULL && father->right==NULL)
	{
		cout<<father->element<<",";
		return;
	}
	if(father->right!=NULL)
		find(father->right);
	if(father->left!=NULL)
		find(father->left);
	cout<<father->element<<",";
}

int main()
{

	int temp;
	int j=0;
	cin>>a;
	const char * split = ",";
    char * p;
    p = strtok (a,split);
    while(p!=NULL) 
    {
        b[j]=atoi(p);
        p = strtok(NULL,split);
        j++;
    } 

	for (int i = 0;i < j ; i++)
	{
		if(i==0)
		{
			root->element=b[i];
			root->left=NULL;
			root->right=NULL;
			root->depth=1;
		}
		else
		{
			Insert(root,b[i],2);
		}
	}
	find(root);

	cout<<endl;
	sort(b,b+j);
 	for(int i=0;i<j;i++)
 		cout<<b[i]<<",";
	return 0;
}
