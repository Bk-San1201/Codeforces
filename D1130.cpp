#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
#define NMAX 5005

vi a[NMAX];
int minval[NMAX];
int n, m;
bool check = true;

void input()
{
    cin >> n >> m;
    int temp1, temp2;
    for (int i = 1; i <= n; i++)
        minval[i] = INT32_MAX;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2;
        a[temp1].push_back(temp2);
        if ((temp2 - temp1 + n) % n <= minval[temp1])
            minval[temp1] = (temp2 - temp1 + n) % n;
    }
    for (int i = 1; i <= n; i++)
        if (a[i].empty())
            minval[i] = 0;
    for (int i = 1; i <= n; i++)
        if (a[i].size() >= 2)
            check = false;
}

int main()
{
    // int ans[NMAX];
    input();
    
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        int dem = n;
        int max_indi = i;
        long long max = 0;
        int max_size = 0;
        while (dem--)
        {
            if (a[j].empty())
            {
                j = j % n + 1;
                continue;
            }
            if (max <= ((a[j].size() - 1) * n + minval[j] + (j - i + n) % n))
            {
                max = (a[j].size() - 1) * n + minval[j] + (j - i + n) % n;
            }
            j = j % n + 1;
        }
        cout << max << " ";
    }
}