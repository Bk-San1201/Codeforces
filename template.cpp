#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005
ll a[11][11];
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            a[i][j] = 4 * (i - 1) + j - 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp = ((i - 1) / 4) * (n / 4) + ((j - 1) / 4);
            tmp *= 16;

            cout << a[(i - 1) % 4 + 1][(j - 1) % 4 + 1] + tmp << " ";
            if (j == n)
                cout << endl;
        }
    }
    return 0;
}
