#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 200005
int T;
ll n, a, b;
string s;
ll in[NMAX];
int len = 0;
ll ans_pip, ans_pil;
void input()
{
    cin >> n >> a >> b;
    cin >> s;
}

void pre_exe()
{
    for (int i = 0; i < n; i++)
        in[i] = 0;
    len = 0;
    int i = 0;
    for (; i < n; i++)
    {
        if (s[i] == '0')
        {
            int cnt = 1;
            i++;
            while (s[i] != '1' && i < n)
            {
                cnt++;
                i++;
            }
            in[len] = cnt;
            len += 1;
        }
    }
    // for (i = 0; i < len; i++)
    //     cout << in[i] << " ";
    // cout << endl;
}

void exe()
{
    ans_pip = n * a;
    ans_pil = (n + 1) * b * 2;
    if (len == 1)
    {
        ans_pil -= (n + 1) * b;
        cout << ans_pip + ans_pil << endl;
        return;
    }
    for (int i = 1; i < len - 1; i++)
    {
        ll tmp = b * (in[i] - 1);
        if (a * 2 < tmp)
        {
            ans_pip += a * 2;
            ans_pil -= tmp;
        }
    }

    // if (a < in[0] * b)
    // {
    ans_pil -= b * in[0];
    ans_pip += a;
    // }

    // if (a < in[len - 1] * b)
    // {
    ans_pil -= b * in[len - 1];
    ans_pip += a;
    // }

    cout << ans_pip + ans_pil << endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> T;
    while (T--)
    {
        input();
        pre_exe();
        exe();
    }
    return 0;
}
