#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int n, m;
int a[101][101];
int b[101][101];
vector<pair<int, int>> in;
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
}
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1)
            {
                return true;
            }
        }
    }
    return false;
}
int cal()
{
    int num = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1)
            {
                num += 1;
                in.push_back({i, j});
                b[i][j] = 1;
                b[i + 1][j] = 1;
                b[i][j + 1] = 1;
                b[i + 1][j + 1] = 1;
            }
        }
    }
    return num;
}

bool isTrue()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void exe()
{
    int num = cal();
    if (num == 0)
    {
        if (check())
        {
            cout << -1;
            return;
        }
        else
        {
            cout << 0;
            return;
        }
    }
    else
    {
        if (isTrue())
        {
            cout << in.size() << endl;
            for (int i = 0; i < in.size(); i++)
            {
                cout << in[i].first << " " << in[i].second << endl;
            }
        }
        else
        {
            cout << -1;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    input();
    exe();
    return 0;
}
