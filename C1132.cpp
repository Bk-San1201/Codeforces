#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define NMAX 5001

int16_t n, q;
vector<int16_t> cell[NMAX];
int16_t del1[NMAX];
int16_t del2[NMAX][NMAX];
void input()
{
    int16_t l, r;
    cin >> n >> q;
    for (int16_t i = 1; i <= q; i++)
    {
        cin >> l >> r;
        for (int16_t k = l; k <= r; k++)
        {
            cell[k].push_back(i);
        }
    }
}

void execute()
{

    int16_t cnt = 0;
    for (int16_t i = 1; i <= n; i++)
    {
        if (cell[i].size() == 0)
            cnt++;
        if (cell[i].size() == 1)
            del1[cell[i][0]]++;
        if (cell[i].size() == 2)
            del2[cell[i][0]][cell[i][1]]++;
    }
    int16_t _max = 0;
    for (int16_t i = 1; i < q; i++)
        for (int16_t j = i + 1; j <= q; j++)
        {
            _max = (_max > n - cnt - del1[i] - del1[j] - del2[i][j]) ? _max : n - cnt - del1[i] - del1[j] - del2[i][j];
        }
    cout << _max;
}

int main()
{
    input();
    execute();
    return 0;
}