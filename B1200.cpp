#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

ll t, n, k, m;
ll h[105];

void exe()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (m < 0)
        {
            cout << "NO\n";
            return;
        }

        if (h[i - 1] >= h[i])
        {
            m += h[i - 1] - h[i];
            if (h[i] - k >= 0)
                m += k;
            else
                m += h[i];
        }
        else if (h[i] - k <= h[i - 1])
        {
            if (h[i] - k <= 0)
                m += h[i - 1];
            else
                m += k - (h[i] - h[i - 1]);
        }
        else
        {
            if (h[i - 1] + m < h[i] - k)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                m -= h[i] - k - h[i - 1];
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        exe();
    }
    return 0;
}
