#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long

bool isChild(string s, string t)
{
    int len_s = s.length();
    int len_t = t.length();
    int indi_t = -1;
    for (int i = 0; i < len_t; i++)
    {
        if (t[i] == s[0])
        {
            indi_t = i;
            break;
        }
    }
    if (indi_t == -1)
        return false;
    for (int i = 1; i < len_s; i++)
    {
        
        int tmp = indi_t;
        for (int j = indi_t + 1; j < len_t; j++)
        {
            if (t[j] == s[i])
            {
                indi_t = j;
                break;
            }
        }
        if (tmp == indi_t)
            return false;
    }
    return true;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    int T;
    
    int cnt[3][26];
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        string s[3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 26; j++)
                cnt[i][j] = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> s[i];
            for (int j = 0; j < s[i].length(); j++)
                cnt[i][s[i][j] - 'a'] += 1;
        }
        if (!isChild(s[0], s[1]))
        {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < 26; i++)
            cnt[1][i] -= cnt[0][i];
        bool check = true;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[1][i] > cnt[2][i] || cnt[1][i] < 0)
                check = false;
        }
        if (check)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        
    }
}