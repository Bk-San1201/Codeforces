#include <iostream>
#include <vector>

using namespace std;

int n;
int a[200005];
vector<int> cnt[200005];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]].push_back(i);
    }
}

void execute()
{
    int max_indi;
    int cnt_max = 0;
    for (int i = 1; i <= 200000; i++)
    {
        if (cnt_max <= cnt[i].size())
        {
            cnt_max = cnt[i].size();
            max_indi = i;
        }
    }
    int ans = n - cnt_max;
    cout << ans << endl;
    int i = 0;
    for (; i < cnt[max_indi].size(); i++)
    {
        if (i == 0)
        {
            for (int k = cnt[max_indi][0] - 1; k >= 1; k--)
            {
                if (a[k] > a[cnt[max_indi][0]])
                {
                    cout << 2 << " " << k << " " << k + 1 << endl;
                }
                else if (a[k] < a[cnt[max_indi][0]])
                {
                    cout << 1 << " " << k << " " << k + 1 << endl;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            for (int k = cnt[max_indi][i] - 1; k > cnt[max_indi][i - 1]; k--)
            {
                if (a[k] > a[cnt[max_indi][0]])
                {
                    cout << 2 << " " << k << " " << k + 1 << endl;
                }
                else if (a[k] < a[cnt[max_indi][0]])
                {
                    cout << 1 << " " << k << " " << k + 1 << endl;
                }
                else
                {
                    break;
                }
            }
        }
    }
    for (int k = cnt[max_indi][i-1] + 1; k <= n; k++)
    {
        if (a[k] > a[cnt[max_indi][0]])
        {
            cout << 2 << " " << k << " " << k - 1 << endl;
        }
        else if (a[k] < a[cnt[max_indi][0]])
        {
            cout << 1 << " " << k << " " << k - 1 << endl;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    input();
    execute();
}