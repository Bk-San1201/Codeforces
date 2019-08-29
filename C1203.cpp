#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int main() 
{
    freopen("input.txt", "r", stdin);
    int n;
    ll a, b;
    cin >> n >> a;
    ll res = a;
    for (int i = 1; i < n; i++)
    {
        cin >> b;
        res = __gcd(res, b);
    }
    vector <int> cnt;
    for (int i = 2; i <= res; i++)
    {
        ll dem = 0;
        while (res % i == 0)
        {
            ++dem;
            res /= i;
        }
        if (dem)
        {
            cnt.push_back(dem);
        }
    }
    ll ans = 1;
    for (int i = 0; i < cnt.size(); i++)
    {
        ans *= cnt[i] + 1;
    }
    cout << ans;
    return 0;
}
