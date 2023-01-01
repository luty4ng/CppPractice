#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int tree[101][4];
char in[101];

void init()
{
	tree[2][2]=int('c');
	tree[3][2]=int('f');
	tree[6][2]=int('d');
	tree[7][2]=int('a');
	tree[10][2]=int('h');
	tree[19][2]=int('b');
	tree[21][2]=int('g');
	tree[32][2]=int('e');
}

void create_huffman()
{
	int flag=0,temp;
	for (int i = 0; i <= 100; ++i)
	{
		if(tree[i][2]!=-1)
		{
			if (flag==0)
			{
				temp=i;
				flag++;
			}
			else if(flag==1)
			{
				flag=0;
				tree[temp+i][0]=temp;
				tree[temp+i][1]=i;
				tree[temp+i][2]=1;
			}
		}
	}
}



int main()
{
	memset(tree,-1,sizeof(tree));
	init();
    create_huffman();

    cin>>in;
    int start=100;
    for (int i = 0; i < strlen(in); ++i)
    {
    	int operation = in[i]-'0';
    	start = tree[start][operation];
    	//cout<<"下一步："<<start<<endl;
    	if(tree[start][2]>=97)
    	{
    		cout<<char(tree[start][2]);
    		start=100;
    	}
    }
	
	return 0;
}
