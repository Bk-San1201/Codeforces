#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int neg_cnt, zer_cnt, pos_cnt;
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    ll *a = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            zer_cnt += 1;
        }
        else if (a[i] > 0)
        {
            pos_cnt += 1;
        }
        else
        {
            neg_cnt += 1;
        }
    }
    if (neg_cnt == 0)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 0)
            {
                sum += abs(a[i] - 1);
            }
        }
        cout << sum;
    }
    else if (neg_cnt % 2 == 0)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                sum += -1 - a[i];
            }
            else
            {
                sum += abs(a[i] - 1);
            }
        }
        cout << sum;
    }
    else
    {
        if (zer_cnt > 0)
        {
            ll sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < 0)
                {
                    sum += -1 - a[i];
                }
                else
                {
                    sum += abs(a[i] - 1);
                }
            }
            cout << sum;
        }
        else
        {
            ll sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < 0)
                {
                    sum += -1 - a[i];
                }
                else
                {
                    sum += abs(a[i] - 1);
                }
            }
            cout << sum + 2;
        }
    }

    return 0;
}
