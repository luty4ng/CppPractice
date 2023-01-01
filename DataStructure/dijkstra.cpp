#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
int inf=9999999,flag=0;

int e[9][9]={
    {inf,inf,inf,inf,inf,inf,inf,inf},
    {inf,inf,2,inf,1,inf,inf,inf},
    {inf,inf,inf,inf,3,10,inf,inf},
    {inf,4,inf,inf,inf,inf,5,inf},
    {inf,inf,inf,2,inf,2,8,4},
    {inf,inf,inf,inf,inf,inf,inf,6},
    {inf,inf,inf,inf,inf,inf,inf,inf},
    {inf,inf,inf,inf,inf,inf,1,inf}
};

int main()
{
    int dis[9],book[10],i,j,n,m,t1,t2,t3,u,v,min;
    int a,b,cnt=0,out[10];
    
    int prev[10];
    char comma;


    memset(book,0,sizeof(book));
    memset(out,0,sizeof(out));
    memset(prev,0,sizeof(prev));

    for (int i = 0; i <= 7; ++i)
	    prev[i]=i;
    cin>>a>>comma>>b;


    for(i=1;i<=7;i++)
        dis[i]=e[a][i];

                                                           

    for(i=1;i<=7;i++)
    {
        min=inf;
        for(j=1;j<=7;j++)
        {
            if(book[j]==0 && dis[j]<min)
            {
                min=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(v=1;v<=7;v++)
        {
            if(e[u][v]!=inf)
            {
                if(dis[v]>dis[u]+e[u][v])
                {
                    dis[v]=dis[u]+e[u][v];
                    prev[v] = u;
                }
            }
        }

    }

    int temp =b;
    int stack[10],top=1;
    stack[0]=b;
    while(temp!=prev[temp])
    {
    	temp = prev[temp];
    	stack[top++]=temp;
    }
    
    if(dis[b]==inf)
    	cout<<-1<<endl;
    else
    {
    	cout<<a<<",";
    	for (int i = top-1; i >= 0; i--)
    	cout<<stack[i]<<",";
    }
    

    return 0;
}
