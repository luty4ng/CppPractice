#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int result[4],flag=0;
string a;



int main()
{
	memset(result,0,sizeof(result));
	int top;
	cin>>a;
	top=a.length();

	for(int i=0;i<top;i++)
	{
		if(a[i]=='{')
			result[3]++;
		if(a[i]=='[')
			result[2]++;
		if(a[i]=='(')
			result[1]++;
		if(a[i]=='}')
			result[3]--;
		if(a[i]==']')
			result[2]--;
		if(a[i]==')')
			result[1]--;
	}

	for (int i = 1; i <=3; i++)
	{
		//cout<<result[i]<<endl;
		if(result[i]==0)
			flag++;
	}

	if(flag==3)
		cout<<0;
	else
	{
		for (int i = 1; i <=3; i++)
			if(result[i]!=0)
				cout<<i<<",";
	}
	return 0;
}


