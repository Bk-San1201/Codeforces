#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f[5001][5001];
int a[5001];
int n;
vector<int> c;

int main()
{
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        // f[i][i] = 0;
    }
    c.push_back(a[1]);
    for (int i = 2; i <= n; ++i)
        if (a[i - 1] != a[i])
            c.push_back(a[i]);
    n = c.size();
    // for (int i = 0; i < n; i++)
    //     cout << c[i]<<endl;
    for (int i = 2; i <= n; ++i)
        for (int j = i - 1; j >= 1; --j)
        {
            if (c[i - 1] == c[j - 1])
            {
                f[j][i] = f[j + 1][i - 1] + 1;
                // cout << j << " " << i << " " << f[j][i] << endl;
            }
            else
            {
                f[j][i] = min(f[j][i - 1], f[j + 1][i]) + 1;
                // cout << j << " " << i << " " << f[j][i] << endl;
            }
        }
    cout << f[1][n];
    return 0;
}