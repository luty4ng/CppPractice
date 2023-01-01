#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

char a[10001],b[10001];
char stack[5000];
float numstack[5000],ans=-1;
int k=0,top=1;


int priority(char x,char y)
{

	if((x=='+'||x=='-')&&(y=='*'||y=='/'))
		return 1;
	else if(x=='&'||x=='(')
		return 1; 
	else 
		return 0;	//弹出
}

int checknumber(char x)
{
	if(x>='0'&&x<='9')
		return 1;
	else 
		return 0;
}

void count()
{
	top=0;
	for (int i = 0; i < k; ++i)
	{
		if(checknumber(b[i]))
		{
			int temp=b[i]-'0';
			numstack[top]=(float)temp;
			//cout<<numstack[top]<<endl;
			top++;
		}
		
		else
		{
			if(top==0)
			{
				ans=numstack[top];
				break;
			}
			//cout<<b[i]<<endl;
			switch(b[i])
			{
				case '+':
				{
					top--;
					numstack[top-1]=numstack[top-1]+numstack[top];
					break;
				}
				case '-':
				{
					top--;
					numstack[top-1]=numstack[top-1]-numstack[top];
					break;
				}
				case '*':
				{
					top--;
					numstack[top-1]=numstack[top-1]*numstack[top];
					break;
				}
				case '/':
				{
					top--;
					numstack[top-1]=numstack[top-1]/numstack[top];
					break;
				}
			}
		}
	}
}




int main()
{
	stack[0]='&';
	cin>>a;
	for (int i = 0; i < strlen(a); ++i)
	{
		if(checknumber(a[i]))
		{
			b[k]=a[i];
			k++;
		}
		else
		{
			if (a[i]=='(')
			{
				stack[top]=a[i];
				top++;
			}
			else if(a[i]==')')
			{
				while(stack[top-1]!='(')
				{

					b[k]=stack[top-1];
					k++;
					top--;
				}
				top--;

			}
			else
			{
				while(priority(stack[top-1],a[i])==0)
				{
					b[k]=stack[top-1];
					k++;
					top--;
				}
				stack[top]=a[i];
				top++;
			}
		}
	}

	for (int i = top-1; i >= 0; i--)
	{
		if(stack[i]!='&' && stack[i]!='(')
		{
			b[k]=stack[i];
			k++;
		}
	}

	count();
	printf("%.2f\n",numstack[0] );
	for (int i = 0; i < k; ++i)
		cout<<b[i]<<" ";
	return 0;
}
