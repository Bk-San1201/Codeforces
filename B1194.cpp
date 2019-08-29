#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define st short int
int main()
{
    freopen("input.txt", "r", stdin);
    int T, n, m;
    int *cnt_row, *cnt_col;
    int *arr;
    string *s;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> n >> m;
        s = new string[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        cnt_col = new int[m];
        cnt_row = new int[n];
        for (int i = 0; i < n; i++)
        {
            cnt_row[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cnt_col[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == '*')
                {
                    cnt_col[j] += 1;
                    cnt_row[i] += 1;
                }
            }
        }
        arr = new int[n * m];
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmp_2 = cnt_row[i] + cnt_col[j];
                if (s[i][j] == '*')
                {
                    arr[tmp] = (m + n) - tmp_2;
                }
                else
                {
                    arr[tmp] = (m + n) - tmp_2 - 1;
                }
                tmp += 1;
            }
        }
        sort(arr, arr + n * m);
        cout << arr[0] << "\n";

    }
}