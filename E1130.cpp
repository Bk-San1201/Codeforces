#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
#define NMAX 5000

void aliceAlgorithm(int n, int *a)
{
    ll res = 0;
    ll cur = 0;
    int k = -1;
    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        if (cur < 0)
        {
            cur = 0;
            k = i;
        }
        res = max(res, (i - k) * cur);
    }
    cout << res << endl;
}

int main()
{
    // int n;
    // int a[NMAX];
    // cin >> n;
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // aliceAlgorithm(n,a);
    ll k;
    cin >> k;
    cout << 2000 << "\n";
    for (int i = 0; i < 1996; i++)
        cout << 0 << " ";
    cout << -1 << " ";
    int remainder = k % 1999;
    int x = 2000 - 1 - remainder - 1;
    ll c;
    cout << 0 << " " << -x;
    c = (k + 1LL * (1 + x) * 2000) / 1999;
    cout << " " << c;

    return 0;
}