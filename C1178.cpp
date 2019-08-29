#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define N 1001
const ll mod = 998244353; 
ll res[N];

void init(int w, int h)
{
    for (int i = 0; i < h; i++)
        res[i] = 1;
    ll pow = 2;
    for (int i = 0; i <= w; i++)
    {
        res[0] *= 2;
        res[0] %= mod;
    }
}
void dp(int w, int h)
{
    init(w, h);
    for (int i = 1; i < h; i++)
    {
        res[i] = res[i - 1] * 2;
        res[i] %= mod;
    }
}

int main() 
{
    // freopen("input.txt", "r", stdin);
    int w, h;
    cin >> w >> h;
    dp(w, h);
    cout << res[h - 1];
    return 0;
}
