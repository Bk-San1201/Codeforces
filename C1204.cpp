#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <queue>

using namespace std;
#define ll long long
#define NMAX 100005

int n;
int arr[101][101];
int m;
int p[1000001];
int len = 2;
vector<int> ans;

void input()
{
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            arr[i][j] = s[j] - '0';
    }
    cin >> m;
    int tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
}

int bfs(int s, int t)
{
    if (s == t)
    {
        return 0;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int *pre = new int[n];
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (arr[vertex][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
                pre[i] = vertex;
            }
            if (visited[t] == true)
            {
                break;
            }
        }
        if (visited[t] == true)
        {
            break;
        }
    }
    int cnt = 1;
    int tmp = t;
    while (pre[tmp] != s)
    {
        tmp = pre[tmp];
        cnt += 1;
    }
    return cnt;
}
void exe()
{

    ans.push_back(p[0]);
    ans.push_back(p[1]);
    int tmp = 0;
    int len_tmp = 1;
    for (int i = 2; i < m; i++)
    {
        int test = bfs(tmp, p[i]);
        if (len_tmp + 1 > bfs(tmp, p[i]))
        {
            tmp = ans[ans.size() - 1];
            ans.push_back(p[i]);
            len_tmp = 1;
        }
        else
        {
            ans.pop_back();
            len_tmp += 1;
            ans.push_back(p[i]);
        }
    }
    // if (ans[len - 1] != p[m - 1])
    // {
    //     len += 1;
    //     ans.push_back(p[m - 1]);
    // }
}
void out()
{
    cout << ans.size() << endl;
    for (int i = 0; i < len; i++)
        cout << ans[i] << " ";
}
int main()
{
    freopen("input.txt", "r", stdin);
    input();
    // cout << bfs(1, 1);
    exe();
    out();
    return 0;
}
