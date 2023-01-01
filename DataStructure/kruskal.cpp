#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
int inf=9999999,flag=0;

int book[12][12],belong[12];

int getf(int v)
{
    if(belong[v]==v)
        return v;
    else
    {
        belong[v]=getf(belong[v]);
        return belong[v];
    }
}

void merge(int v,int u)
{
    int a,b,temp;
    a=getf(v);
    b=getf(u);
    temp=belong[b];
    if(a!=b)
        for (int i = 0; i < 11; ++i)
            if(belong[i]==temp)
                belong[i]=a;
    return;
}

void kruskal(int a,int b)
{
    int lengthsort[30]={1,1,2,2,2,3,3,3,4,4,4,5,6,6,7,8,10,11,11};
    int link[2][20]=
    {
        {5,3,2,5,6,1,2,6,1,1,8,4,3,4,9,7,2,5,6},
        {9,7,5,8,7,2,6,9,4,5,9,5,6,8,10,10,3,6,10}
    };

    for (int i = 0; i < 20; ++i)
        if(a+1==link[0][i] && b+1==link[1][i])
        {
            lengthsort[i]=inf;
            link[0][i]=-1;
            link[1][i]=-1;
        }


    for (int i = 0; i < 11; ++i)
        belong[i]=i;

    for (int i = 0; i < 20; ++i)
    {
        if((belong[link[0][i]]!=belong[link[1][i]]) && lengthsort[i]!=inf && link[0][i]!=-1 && link[1][i]!=-1)
        {
            cout<<lengthsort[i]<<",";
            merge(belong[link[0][i]],belong[link[1][i]]);       
        }
    }
}




int main(int argc, char const *argv[])
{
    char comma,A,B;
    int a,b;
    cin>>A>>comma>>B;
    a=(int)(A-'A');
    b=(int)(B-'A');

    memset(book,0,sizeof(book));
    memset(belong,-1,sizeof(belong));
    if(a<b)
        kruskal(a,b);
    else
        kruskal(b,a);

    return 0;
}
