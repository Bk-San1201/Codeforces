#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll unsigned long long
#define NMAX 100005
#define div 998244353
ll n;
ll a[NMAX];
int num_dig[11];

int cnt_digit(ll x)
{
    int cnt = 0;
    while (x != 0)
    {
        x /= 10;
        cnt += 1;
    }
    return cnt;
}

ll modify(int x, int indi)
{
    int dig[20];
    int max_dig = cnt_digit(x);
    for (int i = 19; i >= 0; i--)
    {
        dig[i] = x % 10;
        x /= 10;
    }
    // for (int i = 0; i <= 19; i++)
    //     cout << dig[i];
    // cout << endl;
    ll res = 0;
    ll j = 19, plus = 10;
    for (int i = 1; i < indi; i++)
    {
        res += 1LL * dig[j] * plus;
        plus *= 100;
        j -= 1;
    }
    while (j != -1 && j >=  19 - indi - max_dig)
    {
        res += 1LL * dig[j] * plus;
        plus *= 10;
        j--;
    }
    return res;
}

ll cnt(int i)
{
    ll res = 0;
    for (int j = 1; j <= 10; j++)
    {
        ll tmp = modify(a[i], j);
        for (int k = 0; k < num_dig[j]; k++)
        {
            res += tmp;
            res %= div;
        }
    }
    return res;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    // ll tmp =  modify(n, 4);
    ll res = 0;
    // cout <<tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        num_dig[cnt_digit(a[i])] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        res += cnt(i);
        res %= div;
    }
    cout << res;
    return 0;
}