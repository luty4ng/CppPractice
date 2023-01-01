#include<stdio.h>
#include<string.h>

char a[10001];
int flag=0;

int main()
{
	scanf("%s",&a);
	int i,j=0;
	//printf("%d",strlen(a));
	for(i=strlen(a)-2;i>=strlen(a)/2-1;i-=2)
	{
	//	printf("%c %c /",a[i],a[j]);
		if(a[i]!=a[j])
			flag=1;	
		j+=2;		
	}
	if(flag==0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
 } 
