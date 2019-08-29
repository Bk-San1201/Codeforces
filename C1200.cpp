#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

ll n, m;
ll q;
ll x, y;
ll a, b, c, d;
ll tmp;
void pre_exe()
{
    tmp = __gcd(n, m);
    x = n / tmp;
    y = m / tmp;
}

ll range(ll x1, ll x2)
{
    if (x1 == 1)
    {
        if (x2 % x == 0)
            return x2 / x;
        else
            return x2 / x + 1;
    }
    else
    {
        if (x2 % y == 0)
            return x2 / y;
        else
            return x2 / y + 1;
    }
}
bool exe()
{
    if (range(a, b) == range(c, d))
        return true;
    return false;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    pre_exe();
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c >> d;
        if (tmp == 1)
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            if (exe())
            {
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";
        }
    }
    return 0;
}
