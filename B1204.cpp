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
    // freopen("input.txt", "r", stdin);
    int n, l, r;
    cin >> n >> l >> r;
    ll min_res = 0;
    min_res = n - (l - 1);
    ll tmp = 2;
    for (int i = 0; i < l - 1; i++)
    {
        min_res += tmp;
        tmp *= 2;
    }
    cout << min_res << " ";
    ll max_res = 0;
    tmp = 1;
    for (int i = 0; i < r - 1; i++)
    {
        max_res += tmp;
        tmp *= 2;
    }
    for (int i = 0; i < n - (r - 1); i++)
    {
        max_res += tmp;
    }
    cout << max_res;
    return 0;
}
