#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n;
pair<int, int> arr[100005];
bool myCompare(pair<int, int> &x, pair<int, int> &y)
{
    return x.first > y.first;
}
long long cal()
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        res += 1LL * arr[i].first * i + 1LL * arr[i].second * (n - 1);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first = arr[i].first - arr[i].second;
    }
    sort(arr, arr + n, myCompare);
    cout << cal();
    return 0;
}