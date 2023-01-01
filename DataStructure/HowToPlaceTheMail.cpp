#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
char a[10001];
long b[10001]={13801014370,13901021320,13621026170};

long hash1(long element)
{
	return element%10;
}

long table2[10];

void insert(long element)
{
	int k=0;
	while(table2[(hash1(element)+k*k)%10]!=0)
		k++;
	table2[(hash1(element)+k*k)%10]=element;
}

int main()
{
	cin>>a;
	int j=3;
	memset(table2,0,sizeof(table2));
	for (int i = 0; i <= j; i++)
		insert(b[i]);
	for (int i = 0; i < 10; ++i)
	{
		cout<<table2[i];
		if (i!=10-1)
			cout<<",";
	}
	return 0;
}
