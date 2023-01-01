#include <iostream>
#include <cstring>

using namespace std;

int inf=9999999,sum=0;

int G[9][9]={
    {inf,inf,inf,inf,inf,inf,inf,inf},
    {inf,inf,2,inf,1,inf,inf,inf},
    {inf,inf,inf,inf,3,10,inf,inf},
    {inf,4,inf,inf,inf,inf,5,inf},
    {inf,inf,inf,2,inf,2,8,4},
    {inf,inf,inf,inf,inf,inf,inf,6},
    {inf,inf,inf,inf,inf,inf,inf,inf},
    {inf,inf,inf,inf,inf,inf,1,inf}
};

int e[9][9];

int dis[11],book[11],n=7,start=1;

int  Prim()
{
    dis[1]=0;
    book[1]=1;


    for (int i = 1; i <= n; ++i)
    {
        int u;
        int MIN = inf;

        for (int j = 1; j <= n; ++j)
        {
            if (book[j]==0 && dis[j] < MIN)
            {
                cout<<"===="<<dis[j]<<endl;
                MIN = dis[j];
                u=j;
            }
        }


        cout<<"min:"<<MIN<<"  u:"<<u<<endl;
        if(MIN!=inf)
            e[i][u]=MIN;
        book[u]=1;
        sum += dis[u];

        for (int v = 1; v <= n; ++v)
        {
            if (G[u][v]!=inf && G[u][v]<dis[v])
                dis[v] = G[u][v];
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    memset(book,0,sizeof(book));
    memset(e,0,sizeof(e));
    memset(dis,inf-1,sizeof(dis));

    for(int i=1;i<=n;i++)
        dis[i]=G[start][i];

    Prim();

    for (int i = 1; i <= n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<e[i][j]<<"    ";
        }
        cout<<endl;
    }
    return 0;
}