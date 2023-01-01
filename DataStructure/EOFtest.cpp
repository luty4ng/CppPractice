#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
 
 using namespace std;

int main()
{
    int a[11],i=0;
    char comma;
    while(cin>>a[i])
    {
        i++;
        cin>>comma;
    }

    for (int i = 0; i <= 10; ++i)
    {
        cout<<a[i]<<",";
    }
}