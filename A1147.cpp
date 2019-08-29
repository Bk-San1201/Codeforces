#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    int *a = new int[2 * n];
    for (int i = 0; i < 2 * n; i++)
        std::cin >> a[i];
    std::sort(a, a + 2 * n);
    if (a[0] == a[2 * n - 1])
        std::cout << -1;
    else
        for (int i = 0; i < 2 * n; i++)
            std::cout << a[i] << " ";
    return 0;
}