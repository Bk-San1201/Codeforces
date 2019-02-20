#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
long long m, n;
long long a[N];
long long sum = 0;
bool myComparator(long long &x, long long &y)
{
    return x > y;
}
void input()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n, myComparator);
}

int checktask(int k)
{
    int cnt = 0;
    int day = 0;
    long long tempOfSum = 0;
    for (int i = 1; i <= n; i++)
    {
        tempOfSum += (a[i]-cnt > 0)*(a[i]-cnt);
        day++;
        if (day == k)
        {
            day = 0;
            cnt++;
        }
    }
    if (tempOfSum < m)
        return -1;
    else
        return k;
}
void binary_check(int l, int r)
{
    int mid = (l + r) / 2;
    int ans = checktask(mid);
    if (l == r)
    {
        cout << ans;
    }
    else
    {
        if (l < r - 1)
        {
            if (ans == -1)
                binary_check(mid, r);
            else
            {
                binary_check(l, mid);
            }
        }
        else
        {
            if (ans == -1)
                binary_check(r,r);
            else
            {
                binary_check(l,l);
            }
        }
    }
}

int main()
{
    input();
    if (sum < m)
    {
        cout << -1;
        return 0;
    }
    if (sum == m)
    {
        cout << n;
        return 0;
    }
    binary_check(1, m);
    return 0;
}