#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <math.h>

using namespace std;

int a[8]={4371,1323,6173,4199,4344,9679,1989};
const int table_size=11;
struct node
{
	int element;
	struct node *next;
};

struct hashtable
{
	struct node *list;
};

int hash1(int element)
{
	return element%10;
}

int hash2(int input)
{
	return 7-(input%7);
}


hashtable table1[table_size];
int table2[table_size];


void init1()
{
	for (int i = 0; i < table_size; ++i)
	{
		node *firstcell = (node *)malloc(sizeof(node));
		//firstcell = NULL;
		table1[i].list = firstcell;
		table1[i].list->next =NULL;
	}
}





void insert1(int element)
{
	node *newcell = (node *)malloc(sizeof(node));
	node *point = table1[hash1(element)].list;
	
	while(point->next != NULL)
		point=point->next;

	point->element = element;
	point->next = newcell;
	newcell->next = NULL;
}

void insert2(int element)
{
	int k=0;
	while(table2[(hash1(element)+k)%table_size]!=-1)
		k++;
	table2[(hash1(element)+k)%table_size]=element;

}

void insert3(int element)
{
	int k=0;
	while(table2[(hash1(element)+k*k)%table_size]!=-1)
		k++;
	table2[(hash1(element)+k*k)%table_size]=element;
}

void insert4(int element)
{
	int k=0;
	while(table2[(hash2(element)+k)%table_size]!=-1)
		k++;
	table2[(hash2(element)+k)%table_size]=element;

}

void insert5(int element)
{
	hashval = hash2(element);
	while(table2[hashval] == -1)
		hashval = hash2(hashval);

	table2[hashval]=element;
}

int main()
{
	cout<<endl<<"分离链表："<<endl;
	init1();
	for (int i = 0; i < 7; i++)
		insert1(a[i]);

	cout<<endl;
	for (int i = 0; i < table_size; ++i)
	{
		node *start = table1[i].list;
		while(start->next!=NULL)
		{
			cout<<start->element<<" ";
			start=start->next;
		}
		cout<<endl;
	}

	cout<<endl<<"线性探测："<<endl;
	memset(table2,-1,sizeof(table2));
	for (int i = 0; i < 7; i++)
		insert2(a[i]);
	for (int i = 0; i < table_size; ++i)
		cout<<table2[i]<<endl;

	cout<<endl<<"平方探测："<<endl;
	memset(table2,-1,sizeof(table2));
	for (int i = 0; i < 7; i++)
		insert3(a[i]);
	for (int i = 0; i < table_size; ++i)
		cout<<table2[i]<<endl;
	
	cout<<endl<<"使用hash2的线性探测："<<endl;
	memset(table2,-1,sizeof(table2));
	for (int i = 0; i < 7; i++)
		insert4(a[i]);
	for (int i = 0; i < table_size; ++i)
		cout<<table2[i]<<endl;

	cout<<endl<<"使用再散列的线性探测："<<endl;
	memset(table2,-1,sizeof(table2));
	for (int i = 0; i < 7; i++)
		insert4(a[i]);
	for (int i = 0; i < table_size; ++i)
		cout<<table2[i]<<endl;


	return 0;
}
