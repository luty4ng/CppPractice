#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r; // int 42
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto f = ci;
    auto &g = ci;

    return 0;
}