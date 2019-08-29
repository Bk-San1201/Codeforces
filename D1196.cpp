#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
int q, n, k;
char s[200005];
int _min[3];
    char tmp[3];
int change(char c)
{
    if (c == 'R')
        return 0;
    if (c == 'G')
        return 1;
    else
        return 2;
}
char change(int c)
{
    if (c == 0)
        return 'R';
    else if (c == 1)
        return 'G';
    else
        return 'B';
}
int cal(char *a, int l, int r)
{
    int len = r - l + 1;
    int sum = len;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == s[l + i])
            sum -= 1;
    }
    return sum;
}
int exe(int l, int r)
{
    // int len = r - l + 1;
    // char *a = new char[len];
    // char *b = new char[len];
    // char *c = new char[len];
    int num = 0;
    
    _min[0] = 0;
    _min[1] = 0;
    _min[2] = 0;
    for (int i = l; i <= r; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            tmp[j] = change((num + j) % 3);
            if (tmp[j] != s[i])
                _min[j] += 1;
        }
        num = (num + 1) % 3;
    }

    int __min = _min[0];
    for (int i = 1; i <= 2; i++)
        if (__min > _min[i])
            __min = _min[i];
    return __min;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> q;
    // exe(1, 10);
    for (int tc = 0; tc < q; tc++)
    {
        // string s;
        cin >> n >> k;
        cin >> s;
        int num = n - k;
        int min = 60000;
        for (int i = 0; i <= num; i++)
        {
            int tmp = exe(i, i + k - 1);
            if (tmp < min)
                min = tmp;
        }
        cout << min << endl;
    }

    return 0;
}
