#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int main() 
{
    freopen("input.txt", "r", stdin);
    int n, m;
    int a[200];
    int b[200];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool tmp1 = binary_search(a, a + n, a[i] + b[j]);
            bool tmp2 = binary_search(b, b + m, a[i] + b[j]);
            if (!tmp1 && !tmp2)
            {
                cout << a[i] << " " << b[j];
                return 0;
            }
        }
    }
    return 0;
}
