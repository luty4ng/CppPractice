#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char c[101];
int b[101];
int increat[6];
int N;

void shell_sort(int a[], int increat[],int len)
{
	int j,increament,temp;
	int k=0;
	while(increat[k]!=0)
	{
		increament = increat[k];
		for(int i=increament;i<len;i++)
		{
			temp = a[i];
			for (j = i; j >= increament;j-=increament)
			{
				if(temp > a[j - increament])
					a[j] = a[j - increament];
				else 
					break;
			}
			a[j]=temp;
		}
		for (int i = 0; i < N; ++i)
			cout<<a[i]<<",";
		cout<<endl;
		k++;
	}
}

int main()
{

	int j=0;
	cin>>N;
	cin>>c;
	const char * split = ",";
    char * p;

    p = strtok (c,split);
    while(p!=NULL) 
    {
        b[j]=atoi(p);
        p = strtok(NULL,split);
        j++;
    }

    j=0;
    cin>>c;
    p = strtok (c,split);
    while(p!=NULL) 
    {
        increat[j]=atoi(p);
        p = strtok(NULL,split);
        j++;
    }

    shell_sort(b,increat,N);
	return 0;
}

