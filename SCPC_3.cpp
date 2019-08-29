#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define ll long long
#define MAX 447213
using namespace std;

int *pre;
int *ans;

bool check(int n)
{
    int temp = n * 2;
    temp = sqrt(temp);
    return (n == (temp * (temp + 1)) / 2);
}
int root(ll n)
{
    int temp = sqrt(2 * n);
    return temp;
}
ll formu(int n)
{
    return (1LL * n * (n + 1)) / 2;
}
void cal()
{
    int temp;
    pre[1] = 1;
    ans[1] = 1;
    for (int i = 2; i <= MAX; i++)
    {
        if (check(i))
        {
            pre[i] = root(i * 1LL);
            ans[i] = pre[i];
        }
        else
        {
            temp = i;
            pre[i] = pre[i - 1];
            temp -= formu(pre[i - 1]);

            ans[i] = ans[formu(pre[i - 1])];
            ans[i] += ans[temp];
        }
    }
}

int exe(ll x, ll y)
{
    int a = root(x);
    int b = root(y);
    int max1 = -1;
    int res;
    if (a == b)
    {
        x -= formu(a);
        y -= formu(a);
        for (int i = x; i <= y; i++)
        {
            if (i < 0 || i > MAX)
                cout << "NGU";
            if (max1 < ans[i])
                max1 = ans[i];
        }
        res = a + max1;
    }
    else if (b == a + 1)
    {
        
        x -= formu(a);
        y -= formu(b);
        for (int i = x; i <= a; i++)
        {
            if (i < 0 || i > MAX)
                cout << "NGU";
            if (max1 < ans[i])
                max1 = ans[i];
        }
        for (int i = 0; i <= y; i++)
        {
            if (i < 0 || i > MAX)
                cout << "NGU";
            if (max1 < ans[i] + 1)
                max1 = ans[i] + 1;
        }
        res = a + max1;
    }
    else
    {
        for (int i = 0; i < b; i++)
        {
            if (i < 0 || i > MAX)
                cout << "NGU";
            if (max1 < ans[i])
                max1 = ans[i];
        }
        y -= formu(b);
        for (int i = 0; i <= y; i++)
        {
            if (i < 0 || i > MAX)
                cout << "NGU";
            if (max1 < ans[i] + 1)
                max1 = ans[i] + 1;
        }
        res = b - 1 + max1;
    }
    return res;
}

int main()
{
    pre = (int *)calloc(MAX + 1, sizeof(int));
    ans = (int *)calloc(MAX + 1, sizeof(int));
    int T;
    ll x, y;
    cal();

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%lld%lld", &x, &y);

        printf("Case #%d\n%d\n", i, exe(x, y));
    }

    return 0;
}
