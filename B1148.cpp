#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
int main()
{
    int m, n, t_a, t_b, k;
    cin >> n >> m >> t_a >> t_b >> k;
    ll *a = new ll[n];
    ll *b1 = new ll[m];
    queue<ll> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] += t_a;
    }
    // ll temp_b;
    for (int i = 0; i < m; i++)
    {
        cin >> b1[i];
        b.push(b1[i]);
    }
    // sort(b1, b1 + m);
    // sort(a, a + n);
    // cout << b.top();
    // sort(b, b + m);
    // int index_of_b = 0;
    ll res = 0;
    if (k >= n || k >= m)
    {
        cout << -1;
        return 0;
    }
    int i = 0;
    while (1)
    {
        if (k == 0)
        {
            while (a[i] > b.front() && !b.empty())
                b.pop();
            if (!b.empty())
                std::cout << b.front() + t_b;
            else
                cout << -1;
            return 0;
        }
        if (b.empty())
            break;
        while (a[i] > b.front())
        {
            b.pop();
            if (b.empty())
            {
                cout << -1;
                return 0;
            }
        }
        if (k != 0)
        {
            if (a[i + k] > b.front())
            {
                k--;
                i++;
                continue;
            }
            else
            {
                if (k != 0)
                {
                    b.pop();
                    k--;
                }
                // cout << b.top();
            }
        }
    }

    cout << -1;
    return 0;
}

