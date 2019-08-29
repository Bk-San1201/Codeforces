#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;
char s[3][2];
int type[3];
pair<int, char> in[3];

bool myComparator(pair <int, char> &x, pair <int, char> &y)
{
    return x.first < y.first;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int num_type = 3;
    cin >> s[0] >> s[1] >> s[2];
    for (int i = 0; i < 3; i++)
    {
        in[i].first = s[i][0] - '0';
        in[i].second = s[i][1];
    }

    for (int i = 0; i < 3; i++)
    {
        if (in[i].second == 'm')
            type[0] += 1;
        else if (in[i].second == 'p')
            type[1] += 1;
        else
            type[2] += 1;
    }
    for (int i = 0; i < 3; i++)
        if (type[i] == 0)
            num_type -= 1;
    if (num_type == 3)
        cout << 2;
    else if (num_type == 2)
    {
        int pos1, pos2;
        if (in[0].second == in[1].second)
        {
            pos1 = 0;
            pos2 = 1;
        }
        else if (in[2].second == in[1].second)
        {
            pos1 = 1;
            pos2 = 2;
        }
        else
        {
            pos1 = 0;
            pos2 = 2;
        }
        if (in[pos1].first == in[pos2].first)
            cout << 1;
        else if (abs(in[pos1].first - in[pos2].first) <= 2)
            cout << 1;
        else 
            cout << 2;
    }
    else
    {
        sort(in, in + 3, myComparator);
        if ((in[2].first - in[0].first) == 0)
        {
            cout << 0;
            return 0;
        }
        if ((in[2].first - in[0].first) == 1)
        {
            cout << 1;
            return 0;
        }
        if (in[0].first + 1 == in[1].first && in[1].first + 1 == in[2].first)
        {
            cout << 0;
            return 0;
        }
        if ((in[2].first - in[0].first) == 2)
        {
            cout << 1;
            return 0;
        }
        if (in[0].first + 2 >= in[1].first || in[1].first + 2 >= in[2].first)
        {
            cout << 1;
            return 0;
        }
        cout << 2;
    }
    return 0;
}