#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define N 1000001
char a[N];
int cnt[N];
vector <int> num_o;

int main()
{
    // freopen("input.txt", "r", stdin);
    int n = 0;
    cin >> a;
    ll i = 1, res = 0;
    if (a[1] == '\0')
    {
        cout << 0;
        return 0;
    }
    while (a[i] != '\0')
    {
        ++n;
        if (a[i] == 'v' && a[i - 1] == 'v')
        {
            cnt[i] += cnt[i - 1] + 1;
        }
        else 
            cnt[i] = cnt[i - 1];

        i++;
    }
    i = 0;
    n += 1;
    // cout << "n = " << n << endl;

    for (i = 0; i < n; i++)
        if (a[i] == 'o')
        {
            num_o.push_back(i);
            // cout << i << endl;
        }
            
    for (i = 0; i < num_o.size(); i++) 
    {
        if (num_o[i] != 0 && num_o[i] != n - 1) 
        {
            res += 1LL * cnt[num_o[i] - 1] * (cnt[n - 1] - cnt[num_o[i]]);
        }

    }
    cout << res;
    return 0;
}
