#include <iostream>
#include <string>

using namespace std;

int cnt[5];
void reset()
{
    for (int i = 0; i < 5; i++)
        cnt[i] = 0;
}
int max()
{
    int tmp = cnt[0];
    for (int i = 1; i < 5; i++)
    {
        if (tmp < cnt[i])
            tmp = cnt[i];
    }
    return tmp;
}
int main()
{
    int n, m;
    int point[1005];
    string s[1005];
    long long sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> point[i];
    }
    for (int i = 0; i < m; i++)
    {
        reset();
        for (int j = 0; j < n; j++)
        {
            cnt[s[j][i] - 'A'] += 1;
        }
        sum += max() * point[i];
    }
    cout << sum;
    return 0;
}