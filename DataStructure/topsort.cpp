#include<cstdio>
#include<cstring>
#include<cstdlib>
#include <iostream>

using namespace std;

int topnum[101];
int indegree[101];
int size=8,n=10;
int G[13][13]=
{
	{0,1,0,0,4,0,0,6,0,0,0},
	{0,0,2,0,0,2,0,0,0,0,0},
	{0,0,0,2,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,4},
	{0,0,0,0,0,3,0,0,0,0,0},
	{0,0,0,2,0,0,3,0,0,3,0},
	{0,0,0,0,0,0,0,0,0,0,3},
	{0,0,0,0,2,1,0,0,6,0,0},
	{0,0,0,0,0,2,0,0,0,6,0},
	{0,0,0,0,0,0,1,0,0,0,4}
};

void topsort()
{
	int queue[101];
	int head=0,tail=0;
	int count=0;
	memset(queue,0,sizeof(queue));
	for (int i = 0; i < n; ++i)
		if(indegree[i]==0)
			queue[tail++]=i;

	while(head!=tail)
	{
		topnum[count++]=queue[head];
		for (int j = 0; j < count; ++j)
			if(G[head][j]!=0)
				if(--indegree[j]==0)
					queue[tail++]=j;
		head++;
	}
	
	
	

}

int main(int argc, char const *argv[])
{
	int a,b,w;
	char x,y,comma;

	cin>>x>>comma>>y;
	memset(indegree,0,sizeof(indegree));
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b>>w;
		G[a][b]=w;
		indegree[b]++;
	}

	topsort();

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cout<<G[i][j]<<" ";
		cout<<endl;
	}

	for (int i = 0; i < n; ++i)
		cout<<topnum[i]<<" ";
	cout<<endl;
	return 0;
}