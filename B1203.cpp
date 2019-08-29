#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005
int a[1001];
int n;

vector<pair<int, int>> in;
void pre_exe()
{
    in.clear();
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
    if (a[n - 2] == a[n - 1])
    {
        tmp.second = dem;
        pair<int, int> abc = tmp;
        in.push_back(abc);
    }
    // for (int i = 0; i < in.size(); i++)
    // {
    //     cout << in[i].first << " " << in[i].second << endl;
    // }
}
void exe()
{
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i].second % 2)
        {
            cout << "NO\n";
            return;
        }
    }
    int len = in.size();
    if (in.size() % 2)
    {
        if (in[in.size() / 2].second % 4)
        {
            cout << "NO\n";
            return;
        }
    }
    int area = in[0].first * in[len - 1].first;
    for (int i = 0; i < len / 2; i++)
    {
        if (in[i].second != in[len - 1 - i].second)
        {
            cout << "NO\n";
            return;
        }
        if (in[i].first * in[len - 1 - i].first != area)
        {
            cout << "NO\n";
            return;
        }
    }
    if (in.size() % 2)
    {
        if (in[in.size() / 2].first * in[in.size() / 2].first != area)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";


}
int main()
{
    freopen("input.txt", "r", stdin);
    int q;

    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 0; i < 4 * n; i++)
        {
            cin >> a[i];
        }
        n *= 4;
        pre_exe();
        exe();
    }
    return 0;
}
