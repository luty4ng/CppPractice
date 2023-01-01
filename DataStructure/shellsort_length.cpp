#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

int result(0);
int k[10] = {3, 56, 76, 13, 27, 5, 18, 49, 38, 65};
int a(0);
int temp[100];
int n(0);

void insertion(int *arr, int len)
{
    int i, j;
    int temp;
    for (i = 1; i < len; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp > arr[j]; j--)
        {
            if (arr[j + 1] != arr[j])
                result++;
            arr[j + 1] = arr[j];
        }
        if (arr[j + 1] != temp)
            result++;
        arr[j + 1] = temp;
    }
}

int main()
{

    cin >> n;

    memset(temp, 0, sizeof(temp));
    while (scanf("%d", &a) != EOF)
    {
        scanf(",");
        for (int i(0); i < a; i++)
        {
            int order(i);
            int j(0);
            while (order < 10)
            {
                temp[j++] = k[order];
                order += a;
            }
            insertion(temp, j);
            order = i;
            j = 0;
            while (order < 10)
            {
                k[order] = temp[j++];
                order += a;
            }
        }
    }
    cout << result << endl;
    return 0;
}