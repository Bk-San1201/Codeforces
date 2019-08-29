#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int a[NMAX * 2];
void exe(int n)
{
    bool check = true;
    int tmp = 0;
    if (n % 2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (check)
            {
                a[i] = ++tmp;
                a[n + i] = ++tmp;
                check = false;
            }
            else
            {
                a[n + i] = ++tmp;
                a[i] = ++tmp;
                check = true;
            }
        }
        cout << "YES\n";
        for (int i = 1; i <= 2 * n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        cout << "NO";
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    exe(n);
    return 0;
}
