#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define NMAX 200005
int n, k;
ll d[NMAX];
int dem1[101];
int dem2[101];
void input()
{
    cin >> n >> k;
    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        d[i] = temp % k;
    }
}

void execute()
{
    int cnt = 0;
    int cnt_zero = 0;
    int cnt_mid = 0;
    // sort(d + 1, d + 1 + n);
    if (k % 2 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == 0)
                cnt_zero++;
            else if (d[i] < k / 2)
                dem1[d[i]]++;
            else if (d[i] > k / 2)
                dem2[k - d[i]]++;
            else
                cnt_mid++;
        }
        // if (k == 2)
        //     cnt_mid = 0;
        cnt = cnt + cnt_mid / 2 + cnt_zero / 2;
        for (int i = 1; i < k / 2; i++)
        {
            cnt += min(dem1[i], dem2[i]);
        }
        cout << cnt * 2;
    }
    else
    {
        if (k == 1)
            cout << n;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == 0)
                cnt_zero++;
            else if (d[i] <= k / 2)
                dem1[d[i]]++;
            else
                dem2[k - d[i]]++;
        }
        cnt += cnt_zero / 2;
        for (int i = 1; i <= k / 2; i++)
        {
            // cout << cnt << endl;
            cnt += min(dem1[i], dem2[i]);
        }

        cout << cnt * 2;
    }
}

int main()
{
    input();
    execute();
    return 0;
}