#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node
{
    int element;
    int depth;
    int height;
    struct node *left;
    struct node *right;
};

node *list[201];

int n,line;
int flag=0;
char a[10001];
int b[10001],head=1,tail=2;

int max(int a1,int b1)
{
    if(a1 > b1)
        return a1;
    else
        return b1;
}


int height(node *temp)
{
    if(temp==NULL)
        return -1;
    else 
        return temp->height;
}

node *SingleRotateWithLeft(node *father)
{
    node *leftson=father->left;
    father->left=leftson->right;
    leftson->right=father;

    father->height=max(height(father->left),height(father->right))+1;
    leftson->height=max(height(leftson->left),father->height)+1;
    //cout<<"左变化后的高度：  爸爸："<<father->height<<"原来左儿子:"<<leftson->height<<endl;
    return leftson;
}

node *SingleRotateWithRight(node *father)
{
    node *rightson=father->right;
    father->right=rightson->left;
    rightson->left=father;

    father->height=max(height(father->left),height(father->right))+1;
    rightson->height=max(height(rightson->right),father->height)+1;

    //cout<<"右变化后的高度：  爸爸："<<father->height<<"原来右儿子:"<<rightson->height<<endl;
    return rightson;
}

node *DoubleRotataWithLeft(node *temp)
{
    temp->left = SingleRotateWithRight(temp->left);
    return SingleRotateWithLeft(temp);
}

node *DoubleRotataWithRight(node *temp)
{
    temp->right = SingleRotateWithLeft(temp->right);
    return SingleRotateWithRight(temp);
}


node *Insert(node *newnode,int number)
{
    if(newnode==NULL)
    {
        //cout<<"create!"<<endl;
        newnode = (node *)malloc(sizeof(node));
        newnode->element = number;
        newnode->left = newnode->right = NULL;
    }
    else
    {
        if(number < newnode->element)
        {
            newnode->left = Insert(newnode->left,number);
            
            if(height(newnode->left) - height(newnode->right) == 2)
            {
                //cout<<"AVL left!"<<endl;
                //cout<<"左边:"<<height(newnode->left)<<" 右边:"<<height(newnode->right)<<endl;
                if(number < newnode->left->element)
                    newnode = SingleRotateWithLeft(newnode);
                else
                    newnode =  DoubleRotataWithLeft(newnode);
            }
        }
        if(number > newnode->element)
        {
            //cout<<"mover and height:"<<newnode->height<<endl;
            newnode->right = Insert(newnode->right,number);

            if(height(newnode->right) - height(newnode->left) == 2)
            {
                //cout<<"AVL right!"<<endl;
                //cout<<"左边:"<<height(newnode->left)<<" 右边:"<<height(newnode->right)<<endl;
                if(number > newnode->right->element)
                    newnode = SingleRotateWithRight(newnode);
                else
                    newnode = DoubleRotataWithRight(newnode);
                
            }
        }
    }
    newnode->height = max(height(newnode->left),height(newnode->right))+1;
    return newnode;
}

void preorder(node *temp)
{
    cout<<temp->element<<",";
    if(temp->left!=NULL)
        preorder(temp->left);
    if(temp->right!=NULL)
        preorder(temp->right);
}

void levelorder(node *temp)
{
    while(head<tail)
    {
        cout<<list[head++]->element<<",";
        if(temp->left!=NULL)
            list[tail++]=temp->left;
        if(temp->right!=NULL)
            list[tail++]=temp->right; 
        if(list[head]!=NULL)
            levelorder(list[head]);
    }
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


    node *T=NULL;
    for (int i = 0; i < j; ++i)
    {
        T = Insert(T , b[i]);
    }

    //preorder(T);
    list[1]=T;
    levelorder(T);

    return 0;
}
