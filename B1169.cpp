#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// int dem[300005][300005];
using namespace std;
// vector <int> a(10);

// bool mycomparator(const vector<int> &u, const vector<int> &v)
// {
//     return u.size() >= v.size();
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> n >> m;
    short **dem = new short *[n + 1];
    for (int i = 1; i <= n; i++)
        dem[i] = new short[n + 1];
    set<int> *a = new set<int>[n + 1];
    pair<int, int> *arr = new pair<int, int>[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        for (int j = 1; j <= n; j++)
        {
            if (j < arr[i].first)
            {
                dem[j][arr[i].first]++;
            }
            else if (j > arr[i].first)
            {
                if (j != arr[i].second)
                    dem[arr[i].first][j]++;
            }
            else
                continue;
        }
        for (int j = 1; j <= n; j++)
        {
            if (j < arr[i].second)
            {
                if (j != arr[i].first)
                    dem[j][arr[i].second]++;
            }
            else if (j > arr[i].second)
                dem[arr[i].second][j]++;
            else
                continue;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < a[i].size(); j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // sort(a + 1, a + 1 + n, mycomparator);
    // ---------------------------------------------

    // for (int i = 1; i <= n; i++)
    //     for (int j = i + 1; j <= n; j++)
    //     {
    //         if (a[i].size() + a[j].size() < m)
    //             continue;
    //         set<int> dis_set = a[i];
    //         dis_set.insert(a[j].begin(), a[j].end());
    //         if (dis_set.size() == m)
    //         {
    //             cout << "YES";
    //             return 0;
    //         }

    //     }
    // cout << "NO";

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (dem[i][j] == m)
            {
                cout << "YES";
                return 0;
            }
    cout << "NO";
    return 0;
}