#include <iostream>

using namespace std;
int main()
{
    int a[11], i = 0;
    cout << "Enter Main" << endl;
    while (cin >> a[i])
    {
        cout << a[i];
        i++;
    }

    for (int i = 0; i <= 10; ++i)
    {
        cout << a[i] << ",";
    }
}