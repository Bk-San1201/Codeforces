#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long

bool isprime(int n)
{
    for (int i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    int num_ed = 0;
    cin >> n;
    // if (n % 2 == 1)
    //     cout << -1;
    // else
    // {
    int i = 0, tmp = n;
    while (1)
    {
        if (isprime(tmp))
        {
            num_ed = tmp;
            break;
        }
        else
        {
            tmp += 1;
        }
    }
    cout << tmp << endl;
    for (int i = 1; i <= n - 1; i++)
    {
        cout << i << " " << i + 1 << endl;
    }
    cout << n << " " << 1 << endl;
    int in = 1, check = 0;
    for (int i = 1; i <= tmp - n; i++)
    {
        cout << in << " " << in + 2 << endl;
        if (check % 2)
            in += 1;
        else
            in += 3;
        check++;
    }
    // }
    return 0;
}
