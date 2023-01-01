#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>

using namespace std;
char c[1001];
int in[1001];
int a[1001];
int b[1001];
int n,N=1;

void swap(int x,int y)
{
	int t;
	t=b[x];
	b[x]=b[y];
	b[y]=t;
}

int min(int x,int y)
{
	if(b[x]>b[y] && b[y]!=0)
		return y;
	else
		return x;
}

void down(int i)
{
	if(b[2*i+1]==0&&b[2*i]==0)
		return;
	int Min = min(2*i,2*i+1);
	if(b[i]>b[Min])
	{
		swap(Min,i);
		//cout<<b[i]<<" "<<b[Min]<<endl;
		down(Min);
	}
	//for (int m = 1; m <= n; ++m)
	//	cout<<b[m]<<" ";
	//cout<<endl;
	

}

void insert(int num,int j)
{
	int i;
	for (i = ++j;a[i/2] > num;i/=2)
		a[i]=a[i/2];
	a[i]=num;
}

int main()
{
	int temp;
	cin>>n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	temp = n;
	while(n!=0)
	{
		N=N*2;
		n/=2;
	}
	N = N/2-1;
	n = temp;


	int j=0;
	cin>>c;
	const char * split = ",";
    char * p;
    p = strtok (c,split);
    while(p!=NULL) 
    {
        in[j]=atoi(p);
        p = strtok(NULL,split);
        j++;
    }

	for (int i = 0; i < n; ++i)
	{
		temp=in[i];
		insert(temp,i);
		b[i+1]=temp;
	}


	for (int i = 1; i <= n; ++i)
	{
		cout<<a[i];
		if(i!=n)
			cout<<",";
	}

	///////////////////////
	cout<<endl;

	for (int i = N; i >=1; i--)
		down(i);

	for (int i = 1; i <= n; ++i)
	{
		cout<<b[i];
		if(i!=n)
			cout<<",";
	}
	return 0;
}
