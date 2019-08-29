#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int arr[500][500];
vector<pair<int, short>> vt[500];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
    {
        sort(arr[i], arr[i] + m);
        vt[i].push_back({arr[i][0], 0});
    }
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] != arr[i][j - 1])
            {
                vt[i].push_back({arr[i][j], j});
            }
        }
    int res = 0;
    int indi = -1;
    for (int i = 0; i < n; i++)
        if (vt[i].size() >= 2)
        {
            indi = i;
            break;
        }
    for (int i = 0; i < n; i++)
    {
        res = res ^ vt[i][0].first;
    }
    if (indi == -1)
    {
        if (res != 0)
        {
            cout << "TAK\n";
            for (int i = 0; i < n; i++)
                cout << vt[i][0].second + 1 << " ";
        }
        else
        {
            cout << "NIE";
        }
    }
    else
    {
        if (res != 0)
        {
            cout << "TAK\n";
            for (int i = 0; i < n; i++)
                cout << vt[i][0].second + 1 << " ";
        }
        else
        {
            cout << "TAK\n";
            for (int i = 0; i < n; i++)
            {

                if (i == indi)
                {
                    cout << vt[i][1].second + 1 << " ";
                    continue;
                }
                cout << vt[i][0].second + 1 << " ";
            }
        }
    }
    return 0;
}