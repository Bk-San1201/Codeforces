#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
ll n, m, k;
vector<pair<ll, ll>> a;

void input()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        pair<ll, ll> temp;
        cin >> temp.first;
        temp.second = i;
        a.push_back(temp);
    }
    return;
}

bool myComparator(const pair<ll, ll> &temp1, const pair<ll, ll> &temp2)
{
    return temp1.first < temp2.first;
}

void _do()
{
    sort(a.begin(), a.end(), myComparator);
    vector<ll> truyvet;
    ll sum = 0;
    for (int i = a.size() - 1; i >= a.size() - m * k; --i)
    {
        sum += a[i].first;
        truyvet.push_back(a[i].second);
    }
    cout << sum << "\n";
    sort(truyvet.begin(), truyvet.end());
    ll dem = 1;
    ll temp = dem;
    if (m == 1)
        for (int i = 0; i < truyvet.size() - 1; i++)
        {
            cout << truyvet[i] << " ";
        }
    else
        while (temp < n && dem < k)
        {
            temp = truyvet[m*dem-1];
            cout << temp << " ";
            ++temp;
            dem++;
        }
}
int main()
{
    input();
    _do();
    return 0;
}
