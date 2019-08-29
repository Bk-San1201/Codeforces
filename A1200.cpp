#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int a[10];
string s;

int find_left_pos()
{
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == 0)
            return i;
    }
}

int find_right_pos()
{
    for (int i = 9; i >= 0; i--)
    {
        if (a[i] == 0)
            return i;
    }
}

void update(int i)
{
    a[i] = 0;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) 
    {
        if (s[i] == 'L')
        {
            a[find_left_pos()] = 1;
        }
        else if (s[i] == 'R')
        {
            a[find_right_pos()] = 1;
        }
        else
        {
            update(s[i] - '0');
        }
    }
    for (int i = 0; i < 10; i++)
        cout << a[i];
    return 0;
}
