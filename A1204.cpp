#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int main() 
{
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int len = s.length() - 1;
    if (s.length() - 1 == 0)
    {
        cout << 0;
    }
    else 
    {
        bool check = false;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != '0')
            {
                check = true;
                break;
            }
        }
        if (len % 2 ==1)
        {
            cout << len / 2 + 1;
        }
        else
        {
            if (!check)
            {
                cout << len / 2;
            }
            else
            {
                cout << len / 2 + 1;
            }
        }
        
    }
    return 0;
}
