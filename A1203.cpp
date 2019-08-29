
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 201
int a[NMAX];
int main() 
{
    freopen("input.txt", "r", stdin);
    int q;
    int n;
    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int pos;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == n)
            {
                pos = i;
                break;
            }
        }
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            if (a[(pos + i) % n] != a[(pos + i + 1) % n] + 1)
            {
                cout << "NO\n";
                check = true;
                break;
            }
        }
        if (!check)
        {
            cout << "YES\n";
        }
    }
    return 0;
}
