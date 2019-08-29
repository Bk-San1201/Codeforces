#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <set>

using namespace std;
#define ll long long
#define NMAX 100005

int n;
int a[2001];

int left_pos()
{
    // bool check = false;
    set<int> tmp;
    tmp.insert(0);
    int len = 1, i = 1;
    for (; i <= n; i++)
    {
        tmp.insert(a[i]);

        if (tmp.size() == len)
        {
            // check = true;
            break;
        }
        len++;
    }
    return i - 1;
}
int right_pos()
{
    set<int> tmp;
    tmp.insert(0);
    int len = 1, i = n;
    for (; i >= 1; i--)
    {
        tmp.insert(a[i]);
        if (tmp.size() == len)
        {
            break;
        }
        len++;
    }
    return i + 1;
}
bool isCheck()
{
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // int n;
    // int a[2001];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    
    int le_pos = left_pos();
    int ri_pos = right_pos();
    if (le_pos == n)
    {
        cout << 0;
        return 0;
    }
    int ans = INT32_MAX;
    set<int> arr[2001];
    for (int i = 1; i <= le_pos; i++)
    {
        arr[i] = arr[i - 1];
        arr[i].insert(a[i]);
    }
    for (int i = 1; i <= le_pos; i++)
    {
        int len = arr[i].size();
        int j = n;
        bool check = true;
        for (; j >= ri_pos; j--)
        {
            arr[i].insert(a[j]);
            if (len == arr[i].size())
            {
                check = false;
                break;
            }          
            len++;
        }
        // if (check)
        // {
        //     j -= 1;
        // }
        if (j - i < ans)
        {
            ans = j - i;
        }
    }
    int res = min (ri_pos - 1, ans);
    cout << res;
    return 0;
}
