#include <iostream>

int main()
{
    int n;
    long long sum = 0;
    std::cin >> n;
    for (int i = 3; i <=n; i++)
    {
        sum += 1LL*i*(i-1);
    }
    std::cout << sum;
    return 0;
}