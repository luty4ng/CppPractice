#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

int Cutoff(3), p;
int number[10] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
int middle(int A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    if (A[Left] > A[Center])
        swap(A[Left], A[Center]);
    if (A[Left] > A[Right])
        swap(A[Left], A[Right]);
    if (A[Center] > A[Right])
        swap(A[Center], A[Right]);

    swap(A[Center], A[Right-1]);
    return A[Right-1];
}
void InsertionSort(int A[], int N)
{
    int j, P;
    int temp;

    for (P = 1; P < N; P++)
    {
        temp = A[P];
        for (j = P; j > 0 && A[j - 1] > temp; j--)
            A[j] = A[j - 1];
        A[j] = temp;
    }             
}

void Qsort(int A[], int Left, int Right)
{
    int i, j;
    int Pivot;
    if (Left + Cutoff <= Right)
    {
        if (Left == 0 && Right == 9)
        {
            Pivot = A[p];
            int t = A[p];
            A[p] = A[Right];
            A[Right] = t;
            i = 0;
            j = 8;
            while(1)
            {
                while (A[i] < Pivot)
                    i++;

                while (A[j] > Pivot)
                    j--;

                if (i < j)
                    swap(A[i], A[j]);
                else
                    break;
            }
            swap(A[i], A[Right]);
        }
        else
        {
            Pivot = middle(A, Left, Right);

            i = Left;
            j = Right-1;
            for (;;)
            {
                while(A[++i]<Pivot){}
                while(A[--j]>Pivot){}

                if (i < j)
                    swap(A[i], A[j]);
                else
                    break;
            }
            
            swap(A[i], A[Right-1]);
        }
        cout << "Qsort(" << Left << ',' << Right << "):";

        for (int i(0); i < 10; i++)
            cout << A[i] << ',';
        cout << endl;
        Qsort(A, Left, i - 1);
        Qsort(A, i + 1, Right); 
    }                           
    else                        
    {
        InsertionSort(A + Left, Right - Left + 1);
        cout << "insert(" << Left << ',' << Right - Left + 1 << "):";
        for (int i(0); i < 10; i++)
            cout << A[i] << ',';
        cout << endl;
    }
}

int main()
{
    cin >> p;

    Qsort(number, 0, 9);
    return 0;
}

