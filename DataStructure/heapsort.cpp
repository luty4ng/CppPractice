#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;
 
char c[1001];
int b[101];	
int len,n;
int flag=1;
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
 

void Heap_build(int a[],int root,int length)
{
	int lchild = root*2+1;
	if (lchild < length)
	{
		int flag = lchild;
		int rchild = lchild+1;
		if (rchild < length)		
		{
			if (a[rchild] > a[flag])
			{
				flag = rchild;
			}
		}
		if (a[root] < a[flag])
		{
			Swap(a[root],a[flag]);
			Heap_build(a,flag,length);
		}
	}
}
 
void Heap_sort(int a[],int len)
{
	for (int i = len/2; i >= 0; --i)
	{
		Heap_build(a,i,len);
		 
	}
	if(n==1)
 	for (size_t i = 0; i < len; ++i)
 		cout<<b[i]<<",";

	for (int j = len-1; j > 0; --j)
	{
		Swap(a[0],a[j]);
		Heap_build(a,0,j);
		flag++;
		if(flag==n)
		for (size_t i = 0; i < len; ++i)
 				cout<<b[i]<<",";
	}
 
}
int main(int argc, char **argv)
{

	int temp;
	int j=0;
	cin>>c;
	cin>>n;

	const char * split = ",";
    char * p;
    p = strtok (c,split);
    while(p!=NULL) 
    {
        b[j]=atoi(p);
        p = strtok(NULL,split);
        j++;
    }
    len=j;
    Heap_sort(b,len);

	return 0;
}