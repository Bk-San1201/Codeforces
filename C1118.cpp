#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[1000];
vector<pair<int, int>> c;

void input()
{
    cin >> n;
    for (int i = 0; i < n * n; i++)
        cin >> a[i];
    sort(a, a + n * n);
    c.push_back({a[0], 1});
    for (int i = 1; i < n * n; i++)
    {
        if (a[i] == a[i - 1])
            c.back().second++;
        else
        {
            c.push_back({a[i], 1});
        }
    }
    // for (vector<pair<int, int>>::iterator it = c.begin(); it != c.end(); ++it)
    //     cout << it->first << " " << it->second << "\n";
}

void runtask()
{
    int ans[50][50];
    if (n % 2 == 0)
    {
        for (vector<pair<int, int>>::iterator it = c.begin(); it != c.end(); ++it)
            if (it->second % 4 != 0)
            {
                cout << "NO";
                return;
            }
        cout << "YES\n";
        vector<pair<int, int>>::iterator it = c.begin();
        for (int i = 1; i <= n / 2; i++)
            for (int j = 1; j <= n / 2; j++)
            {
                ans[i][j] = it->first;
                ans[i][n - j + 1] = it->first;
                ans[n - i + 1][j] = it->first;
                ans[n - i + 1][n - j + 1] = it->first;
                it->second -= 4;
                if (it->second == 0)
                    it++;
            }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
    else
    {
        int mid = n / 2 + 1;
        int check_odd = 0;
        for (vector<pair<int, int>>::iterator it = c.begin(); it != c.end(); ++it)
            if (it->second % 2 == 1)
            {
                ans[mid][mid] = it->first;
                it->second--;
                check_odd++;
            }
        if (check_odd != 1)
        {
            cout << "NO";
            return;
        }
        check_odd = 0;
        vector<pair<int, int>>::iterator it = c.begin();

        check_odd = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            for (int j = 1; j <= n / 2; j++)
            {
                while (it->second < 4)
                    it++;
                if (it == c.end())
                    break;
                ans[i][j] = it->first;
                ans[i][n - j + 1] = it->first;
                ans[n - i + 1][j] = it->first;
                ans[n - i + 1][n - j + 1] = it->first;
                it->second -= 4;
                check_odd++;
            }
            if (it == c.end())
                break;
        }
        if (check_odd != (n / 2) * (n / 2))
        {
            cout << "NO";
            return;
        }
        it = c.begin();
        check_odd = 0;
        for (int i = 1; i < n; i++)
        {
            while (it->second == 0)
            {
                it++;
                if (it == c.end())
                    break;
            }
            if (it == c.end())
                break;
            if (i < mid)
            {
                ans[mid][i] = it->first;
                ans[mid][n - i + 1] = it->first;
                it->second -= 2;
                check_odd++;
            }
            else
            {
                ans[i - n / 2][mid] = it->first;
                ans[n - i + n / 2 + 1][mid] = it->first;
                it->second -= 2;
                check_odd++;
            }
        }
        if (check_odd != n - 1)
        {
            cout << "NO";
            return;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

int main()
{
    input();
    runtask();
    return 0;
}