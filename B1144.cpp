#include <iostream>
#include <vector>
#include <algorithm>

bool myComparator(int &x, int &y)
{
    return x > y;
}
using namespace std;

#define N_MAX 2000

int n;
vector<int> odd;
vector<int> even;
long long a[N_MAX];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            even.push_back(a[i]);
        }

        else
        {
            odd.push_back(a[i]);
        }
    }
}

void execute()
{
    int cnt1 = even.size();
    int cnt2 = odd.size();
    long long sum = 0;
    if (n == 1)
    {
        cout << 0;
        return;
    }
    if (abs(cnt1 - cnt2) <= 1)
    {
        cout << 0;
        return;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    if (cnt1 > cnt2)
    {
        for (int i = 0; i <cnt1 - cnt2 -1; i++)
            sum += even[i];
    }
    else
    {
        for (int i = 0; i <cnt2 - cnt1 -1; i++)
            sum += odd[i];
    }
    cout << sum;
    return;
    
}
int main()
{
    input();
    execute();
}