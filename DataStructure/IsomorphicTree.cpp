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

node *root1 = (node *)malloc(sizeof(node));
node *root2 = (node *)malloc(sizeof(node));

int n,d1,d2,flag=0;


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

void Insert2(node *father,int number,int d)
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
			if(d1<d)
				d1=d;
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
			if(d2<d)
				d2=d;
		}
		else
		{
			Insert(father->left,number,d+1);
		}
	}
}

void find(node *father,int line)
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
		find(father->left,line);
	if(father->right!=NULL)
		find(father->right,line);
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
			root1->element=temp;
			root1->left=NULL;
			root1->right=NULL;
			root1->depth=1;
		}
		else
		{
			Insert(root1,temp,2);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>temp>>comma;
		if(i==0)
		{
			root2->element=temp;
			root2->left=NULL;
			root2->right=NULL;
			root2->depth=1;
		}
		else
		{
			Insert(root2,temp,2);
		}
	}

	if(d1==d2)
		for (int i = 1; i <= d1; ++i)
			if(find(root1,i)!=find(root2,i))
				flag=1;
	else 
		flag = 1;
	if(flag==1)
		cout<<"非同构！"<<endl;
	else
		cout<<"同构！"<<endl;
	return 0;
}


//O(NlogN)