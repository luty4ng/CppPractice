#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

char str[21];
int a[21];

int main()
{
    int j = 0;
    cin >> str;
    char *p;
    p = strtok(str, ",");
    while (p != NULL)
    {
        a[j] = atoi(p);
        p = strtok(NULL, ",");
        j++;
    }

    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << ",";
    }
}