#include <iostream>

using namespace std;

#define ll long long

void runtask(ll n, int a, int b)
{
    ll ans;
    if (2 * a > b)
    {
        ans = (n / 2) * b + ((n % 2) ? a : 0);
        cout << ans << "\n";
    }
    else
    {
        cout << a * n << "\n";
    }
}

int main()
{
    int q;
    ll n[10005];
    int a[10005];
    int b[10005];
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> n[i] >> a[i] >> b[i];
        runtask(n[i], a[i], b[i]);
    }
    return 0;
}