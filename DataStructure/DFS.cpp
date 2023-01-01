#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
int inf=9999999;
int book[12];
int G[9][9]=
{
    {inf,inf,inf,inf,inf,inf,inf,inf,inf},
    {inf,inf,1,1,inf,inf,inf,inf,inf},
    {inf,1,inf,inf,1,1,inf,inf,inf},
    {inf,1,inf,inf,inf,inf,1,1,inf},
    {inf,inf,1,inf,inf,inf,inf,inf,1},
    {inf,inf,1,inf,inf,inf,inf,inf,1},
    {inf,inf,inf,1,inf,inf,inf,inf,1},
    {inf,inf,inf,1,inf,inf,inf,inf,1},
    {inf,inf,inf,inf,1,1,1,1,inf}
};

void DFS(int now)
{
    int flag=0;
    book[now]=1;
    cout<<now<<",";
    for (int i = 1; i <=8 ; ++i)
    {
        if (G[now][i]!=inf && book[i]!=1)
        {
            flag=1;
            DFS(i);
        }
    }
    if(flag!=1)
        return;
}

int main(int argc, char const *argv[])
{
    int start;
    cin>>start;
    memset(book,0,sizeof(book));
    book[start]=1;
    DFS(start);
    return 0;
}
