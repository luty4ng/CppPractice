#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

char str[21];
int a[21],n,len,MAX=-1;
int list[11],newa[21],flag=0;

int countbit(int x,int bit)
{
    x/=10;
    if(x!=0)
        countbit(x,bit+1);
    else
        return bit;
}


void Rsort()
{
    int order;
    for (int i = 1; i <= MAX; ++i)
    {
        memset(list,0,sizeof(list));
        for (int j = 0; j < len; ++j)
        {
            order = a[j]%(int)pow(10,i)/(int)pow(10,i-1);
            list[order]++;
        }
        
        for (int j = 1; j < 10; ++j)
            list[j]+=list[j-1];

        for (int j = len-1; j >= 0; j--)
        {
            order = a[j]%(int)pow(10,i)/(int)pow(10,i-1);
            newa[--list[order]]=a[j];
        }

        for (int j = 0; j < len; ++j)
            a[j]=newa[j];

        if(i==n)
        {
            flag=1;
            for (int j = 0; j < len; ++j)
                cout<<a[j]<<",";
        }

    }
}


int main()
{
    cin>>str;
    int j=0;
    char *p;
    p = strtok(str,",");
    while(p!=NULL)
    {
        a[j] = atoi(p);
        if(countbit(a[j],1)>MAX)
            MAX=countbit(a[j],1);
        p = strtok(NULL,",");
        j++;
    }
    len=j;
    cin>>n;
    Rsort();
    if(flag!=1)
        for (int j = 0; j < len; ++j)
            cout<<a[j]<<",";

    return 0;
}