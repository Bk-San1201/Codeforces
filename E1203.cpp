#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 150005
int n;
bool check[NMAX];
int a[NMAX];

vector<pair<int, int>> in;
void pre_exe()
{
    // in.clear();
    sort(a, a + n);
    int dem = 1;
    pair<int, int> tmp;
    tmp.first = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            dem += 1;
        }
        else
        {
            tmp.second = dem;
            pair<int, int> abc = tmp;
            in.push_back(abc);
            dem = 1;
            tmp.first = a[i];
        }
    }
    // if (a[n - 2] == a[n - 1])
    // {
    tmp.second = dem;
    pair<int, int> abc = tmp;
    in.push_back(abc);
    // }
    // for (int i = 0; i < in.size(); i++)
    // {
    //     cout << in[i].first << " " << in[i].second << endl;
    // }
}
int cnt()
{
    int res = 0;
    int i = 0;
    if (in[i].first == 1)
    {
        res += 1;
        if (check[2] == false && in[i].second >= 2)
        {
            res += 1;
            check[2] = true;
        }

        i += 1;
    }
    for (; i < in.size(); i++)
    {
        res += 1;
        if (in[i].second == 2)
        {
            if (check[in[i].first - 1] == false || check[in[i].first + 1] == false)
            {
                res += 1;
                if (check[in[i].first - 1] == true)
                    check[in[i].first + 1] = true;
                else
                {
                    check[in[i].first - 1] = true;
                }
                
            }
        }
        if (in[i].second >= 3)
        {
            if (!check[in[i].first - 1])
            {
                res += 1;
                check[in[i].first - 1] = true;
            }

            if (!check[in[i].first + 1])
            {
                res += 1;
                check[in[i].first + 1] = true;
            }
        }
    }
    ll ans = 0;
    for (int k = 1; k <= 150001; k++)
        if (check[k])
            ans += 1;
    return ans;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        check[a[i]] = true;
    }
    pre_exe();
    ll res = cnt();
    cout << res;
    return 0;
}
