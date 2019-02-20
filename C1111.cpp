#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define ll long long
#define MAXL 100005

int n, k, A, B;
vector<ll> pos;

void input()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> A >> B;
    for (int i = 0; i < k; ++i)
    {
        ll temp;
        cin >> temp;
        pos.push_back(temp);
    }
        // cin >> pos[i];
    sort(pos.begin(), pos.end());
}

ll ans(ll l, ll r)
{
    ll len = r - l + 1;
    ll powConsumed;
    ll mid = (r + l) / 2;
    ll lIndex = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
    ll rIndex = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
    rIndex--;
    ll noAvenger = rIndex - lIndex + 1;
    if (!noAvenger)
        powConsumed = A;
    else
        powConsumed = B * noAvenger * len;
    if (l == r || !noAvenger)
        return powConsumed;
    return min(powConsumed, ans(l, mid) + ans(mid + 1, r));
}

int main()
{
    input();
    cout << ans(1, pow(2,n));
    return 0;
}