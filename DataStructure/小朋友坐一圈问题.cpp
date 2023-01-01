#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct circle
{
    int number;
    struct circle *next;
};
circle *head=(circle *)malloc(sizeof(circle));
circle *pre;

int start=1;
int main()
{
    int m,n;
    scanf("%d,%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        circle *temp=(circle *)malloc(sizeof(circle));
        if(i>1)
            pre->next=temp;
        if(i==1)
            head=temp;
        
        temp->number=i;
        pre=temp;
        if(i==m)
            pre->next=head;
    }
    circle *t=head;
    circle *p;
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            p=t;
            t=t->next;
        }
        cout<<t->number;
        if(j<m)
            cout<<",";
        free(t);
        p->next=t->next;
        t=t->next;
    }
    return 0;
}

