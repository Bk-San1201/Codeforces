#include <iostream>
#include <queue>

using namespace std;
#define ll long long

ll m, n, k;
ll b[100005];
priority_queue<int, vector<int>, greater<int>> hieu;
ll ans[100005];
// ll sum[100005];

void input()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        // if (i != 0)
        //     sum[i] += b[i] + sum[i - 1];
        // else
        //     sum[i] = b[i];
    }

    return;
}

void dp()
{
    for (int i = 1; i <= k; i++)
    {
        ans[i - 1] = i;
        while (i != k)
        {
            hieu.push(b[i] - b[i - 1]);
            break;
        }
    }
    for (int i = k; i < n; ++i)
    {
        hieu.push(b[i] - b[i - 1]);
        ans[i] = ans[i - 1] + hieu.top() + 1 -2 +1;
        hieu.pop();
    }
}

int main()
{
    input();
    dp();
    cout << ans[n - 1];
    return 0;
}