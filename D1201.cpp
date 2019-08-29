#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 200005

int n, m, k, q;
int b[NMAX];
vector<int> trea[NMAX];
ll ans_lef[NMAX];
ll ans_rig[NMAX];


bool myComparator(const pair<int, int> &x, const pair<int, int> &y)
{
    if (x.first == y.first)
    {
        return x.second < y.second;
    }
    return x.first < y.first;
}

void pre_exe()
{
    vector<pair<int, int>> tmp;
    int r, c;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;
        tmp.push_back({r, c});
    }
    sort(tmp.begin(), tmp.end(), myComparator);
    for (int i = 0; i < q; i++)
    {
        cin >> b[i];
    }
    sort(b, b + q);
    for (int i = 0; i < tmp.size(); i++)
    {
        trea[tmp[i].first].push_back(tmp[i].second);
    }
}

int findShortestColumn(int pos)
{
    if (binary_search(b, b + q, pos))
    {
        return upper_bound(b, b + q, pos - 1) - b;
    }
    if (pos < b[0]) {
        return b[0];
    }
    if (pos > b[q - 1])
    {
        return b[q - 1];
    }
    int lef = lower_bound(b, b + q, pos) - b - 1;
    int rig = upper_bound(b, b + q, pos) - b;
    if (pos - lef > rig - pos) 
    {
        return rig;
    }
    else
    {
        return lef;
    }
}

void san()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < trea[i].size(); j++)
            cout << i << " " << trea[i][j] << endl;
    }
    cout << findShortestColumn(4);
}

void exe()
{
    // Initial
    ans_lef[1] = 
}

int main()
{
    freopen("input.txt", "r", stdin);
    pre_exe();
    san();
    return 0;
}
