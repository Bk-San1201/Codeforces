#include <iostream>
#include <algorithm>

using namespace std;

#define ll int
ll q;
ll a[1000];
ll ans[1000];

int _do(int k)
{
    ll max = 0;
    for (int i = 1; i < a[k]; i++)
        if (max < __gcd(a[k] ^ i, a[k] & i))
            max = __gcd(a[k] ^ i, a[k] & i);
    return max;
}

int main()
{
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a[i];
        ans[i] = _do(i);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;   
}