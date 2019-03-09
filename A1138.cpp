#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int a[100000];
    vector <int> res;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == a[i+1])
            cnt++;
        else
        {
            res.push_back(cnt);
            cnt = 1;
        }
    }
    int ans = -1;
    for (int i = 0; i < res.size()-1; i++)
        if (ans < min(res[i], res[i+1]))
            ans = min(res[i], res[i+1]);
    cout << ans * 2;
    return 0;
}