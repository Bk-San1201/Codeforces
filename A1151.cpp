#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cal_min(int m, int n)
{
    int res1 = abs(m - n);
    int res2 = 25 - res1 + 1;
    return ((res1 > res2) ? res2 : res1);
}
int main()
{
    int n;
    string s;
    int min = 100000, min_temp;
    int a[50];
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - 65;
        // cout << a[i] << "\n";

    }
    // cout << cal_min(25,0) << cal_min(2, 2) << cal_min(19,19) << cal_min(7,25);
    for (int i = 0; i < n - 3; i++)
        for (int j = i + 1; j < n - 2; j++)
            {
                    min_temp = cal_min(a[i], 0) + cal_min(a[i+1], 2) + cal_min(a[i+2], 19) + cal_min(a[i+3], 6);
                    if (min > min_temp) 
                        min = min_temp;
            }
    cout << min;
    return 0;
}