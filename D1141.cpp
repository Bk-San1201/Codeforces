#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
struct data
{
    int dem;
    queue<int> vitri;
};
struct data l[500];
struct data r[500];
int n;
vector<pair<int, int>> ans;

void putans(int x, int y)
{
    pair<int, int> temp;
    temp.first = x;
    temp.second = y;
    ans.push_back(temp);
}

int main()
{
    cin >> n;
    char le[150001];
    char ri[150001];
    cin >> le;
    cin >> ri;
    for (int i = 0; i < n; i++)
    {
        l[le[i]].dem++;
        l[le[i]].vitri.push(i + 1);
        r[ri[i]].dem++;
        r[ri[i]].vitri.push(i + 1);
    }
    int res = 0;
    for (int i = 97; i <= 122; i++)
    {
        int temp = min(l[i].dem, r[i].dem);
        l[i].dem -= temp;
        r[i].dem -= temp;
        res += temp;
        for (int j = 0; j < temp; j++)
        {
            putans(l[i].vitri.front(), r[i].vitri.front());
            l[i].vitri.pop();
            r[i].vitri.pop();
        }
    }
    int i = 97;
    while (!l[63].vitri.empty() && i <= 122)
    {
        while (!r[i].vitri.empty() && !l[63].vitri.empty())
        {
            putans(l[63].vitri.front(), r[i].vitri.front());
            res++;
            l[63].vitri.pop();
            r[i].vitri.pop();
        }
        i++;
    }
    i = 97;
    while (!r[63].vitri.empty() && i <= 122)
    {
        while (!l[i].vitri.empty() && !r[63].vitri.empty())
        {
            putans(l[i].vitri.front(), r[63].vitri.front());
            res++;
            r[63].vitri.pop();
            l[i].vitri.pop();
        }
        i++;
    }
    while (!l[63].vitri.empty() && !r[63].vitri.empty())
    {
        putans(l[63].vitri.front(), r[63].vitri.front());
        res++;
        l[63].vitri.pop();
        r[63].vitri.pop();
    }
    cout << res << endl;
    if (res == 0)
        return 0;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
}