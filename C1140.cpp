#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define ll long long

int n, k;
pair<ll, ll> arr[300000];
ll res[300000];
ll min_res[300000];
multiset<int, greater<int>> t;

bool comparator(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, comparator);
}

void execute()
{
    for (int i = 0; i < n; i++)
    {
        // t.push();
    }
}

int main()
{
}