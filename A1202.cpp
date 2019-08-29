#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

ll cnt(string s)
{
    ll cnt = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != '0')
        {
            return cnt;
        }
        cnt++;
    }
    return cnt;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int T;
    string s, t;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        cin >> s >> t;
        ll x = cnt(s);
        ll y = cnt(t);
        if (x == 0 && y == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        else if (x == 0 && y != 0)
        {
            int cnt = 0;
            for (int i = s.length() - y - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    cnt += 1;
                }
                else
                {
                    break;
                }
            }
            cout << cnt << "\n";
        }
        else
        {
            if (y > x)
            {
                int cnt = 0;
                for (int i = s.length() - y - 1; i >= 0; i--)
                {
                    if (s[i] == '0')
                    {
                        cnt += 1;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << cnt << "\n";
            }
            else
                cout << x - y << "\n";
        }
        // cout << x << " " << y;
    }
    return 0;
}
