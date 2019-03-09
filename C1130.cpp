#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define N 100

int n;
int a[N][N];
pair<int, int> cur_pos;
pair<int, int> destinate;
bool check[N][N];
bool ans = false;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;
bool check_1 = true;
void input()
{
    cin >> n;
    cin >> cur_pos.first >> cur_pos.second;
    cin >> destinate.first >> destinate.second;
    string s[N];
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < n; j++)
        {
            a[i][j + 1] = s[i][j] - '0';
            check[i][j + 1] = false;
        }
    }
    return;
}

void dfs(int i, int j)
{
    if (check_1)
        v1.push_back({i, j});
    else
        v2.push_back({i, j});
    if (i == destinate.first && j == destinate.second)
        ans = true;
    // cout << "dang o dinh " << i << " " << j << " " << ans << endl;
    if (!check[i][j + 1] && j + 1 <= n && a[i][j + 1] == 0)
    {
        check[i][j + 1] = true;
        // cout << "dang o dinh "<< i <<" "<< j+1 << endl;
        dfs(i, j + 1);
    }
    if (!check[i + 1][j] && i + 1 <= n && a[i + 1][j] == 0)
    {
        check[i + 1][j] = true;
        // cout << "dang o dinh "<< i+1 <<" "<< j << endl;
        dfs(i + 1, j);
    }
    if (!check[i][j - 1] && j - 1 > 0 && a[i][j - 1] == 0)
    {
        check[i][j - 1] = true;
        //  cout << "dang o dinh "<< i <<" "<< j-1 << endl;
        dfs(i, j - 1);
    }
    if (!check[i - 1][j] && i - 1 > 0 && a[i - 1][j] == 0)
    {
        check[i - 1][j] = true;
        // cout << "dang o dinh "<< i-1 <<" "<< j << endl;
        dfs(i - 1, j);
    }
}

long long  distance(pair<int, int> a, pair<int, int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main()
{
    input();
    int i = 1, j = 1;
    dfs(cur_pos.first, cur_pos.second);
    if (ans)
    {
        cout << 0;
        return 0;
    }

    check_1 = false;
    dfs(destinate.first, destinate.second);

    long long ans_1 = -1;
    long long temp = 9999999;
    // for (int i = 0; i < v1.size(); i++)
    //     cout << v1[i].first << " " << v1[i].second << "\n";
    //     cout <<"----\n";
    // for (int i = 0; i < v2.size(); i++)
    //     cout << v2[i].first << " " << v2[i].second << "\n";
    for (int i = 0; i < v1.size(); i++)
        for (int j = 0; j < v2.size(); j++)
        {
            if (temp > distance(v1[i], v2[j]))
            {
                temp = distance(v1[i], v2[j]);
                // ans_1 = abs(v1[i].first - v2[i].first) + abs(v1[i].second - v2[i].second);
            }
        }
    cout << temp;

    return 0;
}