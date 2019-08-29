#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 400005
ll a[NMAX];
ll n, I;
ll num[NMAX];
ll dp[100];

struct san
{
    int val;
    int i;
    int j;
};

bool compara(san &k, san&b) {
    return k.val < b.val;
}
void in()
{
    cin >> n >> I;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

ll log(ll k)
{
    return (int)ceil(log2(1.0 * k));
}
void exe()
{
    sort(a + 1, a + n + 1);
    I = 8 * I;
    // int cnt = 1;
    ll num_dif = 1;
    num[1] += 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            num[num_dif] += 1;
        }
        else
        {
            num_dif += 1;
            num[num_dif] += 1;
        }
    }
    // ll n_tmp = n;
    for (int i = 1; i <= num_dif; i++) {
        dp[i] = dp[i - 1] + num[i];
    }
    ll n_tmp = n;
    n = I/ n;
    if (n >= 32) {
        cout << 0;
        return;
    }
    n = pow(2, n);
    if (num_dif <= n) {
        cout << 0;
        return;
    }
    else {
        // ll k = num_dif - n;
        ll Min = 999999999;
        // ll res = 0;
        for (int i = 1; i <= num_dif - n + 1; i++) {
            ll tmp = dp[i - 1] + (dp[num_dif] - dp[i + n - 1]);
            if (tmp < Min) {
                Min = tmp;
            }
        }
        cout << Min;
    }

}
int main()
{
    // cout << ceil(log2(7.9999));
    // freopen("input.txt", "r", stdin);
    in();
    exe();
    return 0;
}
