#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005
int k, n;
string s[2005];
ll row_cnt[2005][2005];
ll col_cnt[2005][2005];
int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 && s[i][j] == 'B')
            {
                row_cnt[i + 1][j + 1] = 1;
                continue;
            }
            if (s[i][j] == 'B')
                row_cnt[i + 1][j + 1] = row_cnt[i + 1][j - 1 + 1] + 1;
            else
                row_cnt[i + 1][j + 1] = row_cnt[i + 1][j - 1 + 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 && s[j][i] == 'B')
                col_cnt[i + 1][j + 1] = 1;
            if (s[j][i] == 'B')
                col_cnt[i + 1][j + 1] = col_cnt[i + 1][j - 1 + 1] + 1;
            else
                col_cnt[i + 1][j + 1] = col_cnt[i + 1][j - 1 + 1];
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (row_cnt[i][n] == 0)
        {
            res += 1;
        }
        if (col_cnt[i][n] == 0)
        {
            res += 1;
        }
    }
    ll max_tmp = -1;
    for (int i = 1; i <= n - k + 1; i++)
    {

        for (int j = 1; j <= n - k + 1; j++)
        {
            ll tmp = 0;
            for (int cnt = 0; cnt < k; cnt++)
            {
                if (row_cnt[i + cnt][j - 1] == 0 && row_cnt[i + cnt][n] - row_cnt[i + cnt][j + k - 1] == 0 && row_cnt[i + cnt][n] != 0)
                {
                    tmp += 1;
                }
                if (col_cnt[j + cnt][i - 1] == 0 && col_cnt[j + cnt][n] - col_cnt[j + cnt][i + k - 1] == 0 && col_cnt[j + cnt][n] != 0)
                {
                    tmp += 1;
                }
            }
            if (max_tmp < res + tmp)
            {
                max_tmp = res + tmp;
            }
        }
    }
    cout << max_tmp;

    return 0;
}
