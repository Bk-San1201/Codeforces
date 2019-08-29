#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define NMAX 200005
#define ll long long
int n, k;
int a[NMAX];
ll sum = 0;

int main() 
{
    freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    for (int tc = 0; tc < q; tc++) 
    {
        cin >> n >> k;
        vector <int> odd_indi;
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 1)
                odd_indi.push_back(i);
            sum += a[i];
        }
        if (k % 2 == 1 && sum % 2 == 0)
        {
            cout << "NO\n";
            continue;
        }
        if (k % 2 == 0 && sum % 2 == 1) 
        {
            cout << "NO\n";
            continue;
        }
        if (odd_indi.size() < k)
        {
            cout << "NO\n";
            continue;
        }
        int indi = 1;
        cout << "YES\n";
        k -= 1;
        while (k--)
        {
            while (1)
            {
                if (a[indi] % 2 == 1)
                {
                    cout << indi << " ";
                    indi += 1;
                    break;
                }
                indi += 1;
            }
        }
        cout << n << endl;


    }
    return 0;
}
