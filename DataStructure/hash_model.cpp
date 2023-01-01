#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node
{
	int element;
	struct node *next;
};

struct hashtable
{
	int size;
	node *lists;
};

int main()
{
	hashtable *H;
	H = (hashtable *)malloc(sizeof(struct hashtable));
	H->lists = (node *)malloc(sizeof(node)*13);
	H->lists[0].element=1;
	H->lists[1].element=2;


	return 0;
}
