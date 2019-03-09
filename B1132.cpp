#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define NMAX 300005
int n;
long long a[NMAX];
// long long b[10];
int m;
int q[NMAX];
long long sum = 0;

bool myComparator(long long &x, long long &y)
{
    return x > y;
}
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> q[i];
}
void execute()
{
    sort(a, a + n, myComparator);
    // sort(q, q+ m, myComparator);
    for (int i = 0; i < m; i++)
    {
        cout << sum - a[q[i] - 1] << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    execute();
    return 0;
}