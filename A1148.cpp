#include <iostream>

int main()
{
    long long int a, b, c;
    long long int res = 0;
    std::cin >> a >> b >> c;
    if (a == b)
    {
        res = a + b + 2 *c;
    }
    else if (a > b)
    {
        res = 2 * b + 1 + 2 * c;
    }
    else
    {
        res = 2 * a + 1 + 2 * c;
    }
    std::cout << res;
    return 0;
}