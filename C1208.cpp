#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define __unique(V) (V).resize(unique((V).begin(), (V).end()) - (V).begin())
#define cntbit(X) __builtin_popcount((X))
#define bit(S, i) (((S) >> (i)) & 1)
#define PI acos(-1)
#define fi first
#define se second
#define LL long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define eb emplace_back
#define TASK "1208C"
using namespace std;
int n;
int a[10][10];
///--------------------------
void readf()
{
    cin >> n;
}
///--------------------------
void solve()
{
    fo(i, 1, 4) fo(j, 1, 4) a[i][j] = (i - 1) * 4 + j - 1;
    fo(i, 1, n) fo(j, 1, n)
    {
        int o = (i - 1 >> 2) * (n >> 2) + (j - 1 >> 2);
        o <<= 4;
        //cerr << i << ' ' << j <<' '<< o << '\n';
        cout << a[(i - 1) % 4 + 1][(j - 1) % 4 + 1] + o << " \n"[j == n];
    }
}
///--------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readf();
    solve();
}