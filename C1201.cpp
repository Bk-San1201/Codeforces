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
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int mid = n / 2;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        a.push_back(j);
    }
    sort(a.begin(), a.end());
    int pos_aft, pos = mid, cnt = 0;
    while (1)
    {
        auto tmp = upper_bound(a.begin(), a.end(), a[pos]);
        pos_aft = tmp - a.begin();
        if (pos_aft >= n)
            pos_aft = n - 1;
        if (pos_aft == n - 1 && a[pos_aft] == a[pos])
        {
            int len = n - mid;
            cnt += k / len;
            k = k % len;
            break;
        }
        else
        {
            int len = pos_aft - mid;
            if (k / len == 0)
                break;
            cnt += min(k / len, a[pos_aft] - a[pos]);

            k -= len * min(k / len, a[pos_aft] - a[pos]);
            pos = pos_aft;
        }
    }
    cout << a[mid] + cnt;

    return 0;
}
