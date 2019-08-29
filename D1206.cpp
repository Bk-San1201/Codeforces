#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int n;
ll a[NMAX];
bool check[NMAX];
int cnt[65];
int arr[NMAX][65];
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void do_sth(ll k, int pos)
{
    int i = 1;
    while (1)
    {
        if (k == 1)
        {
            cnt[i] += 1;
            arr[pos][i] += 1;
            return;
        }
        else
        {
            cnt[i] += k % 2;
            arr[pos][i] += 1;
            k /= 2;
            i++;
        }
    }
}
void pre_exe()
{
    for (int i = 0; i < n; i++)
    {
        do_sth(a[i], i);
    }
}
bool do_check(int pos)
{
    int cnt = 0;
    for (int i = 0; i < 65; i++)
    {
        if (arr[pos] != 0)
            cnt++;
    }
    if (cnt == 1)
        return true;
    else
        return false;
}
void exe()
{
    for (int i = 0; i < 65; i++)
    {
        if (cnt[i] >= 3)
        {
            cout << "3";
            return;
        }
    }
    int dem = 0;
    for (int i = 0; i < 65; i++)
    {
        if (cnt[i] == 2)
        {
            bool c = true;
            for (int pos = 0; pos < n; pos++)
            {
                if (arr[pos][i] != 0)
                {
                    if (do_check(i))
                    {
                        c = false;
                    }
                }
            }
            if (c)
            {
                dem += 1;
            }
        }
    }
    if (dem >= 3)
        cout << dem;
    else
        cout << "-1";
}
int main()
{
    freopen("input.txt", "r", stdin);
    input();
    pre_exe();
    exe();
    return 0;
}
