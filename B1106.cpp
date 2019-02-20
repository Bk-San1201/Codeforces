#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define ll long long
using namespace std;

struct customer
{
    int type;
    int num_dish;
};

struct value
{
    ll c;
    ll indi;
    ll a;
};

struct customer ds[100005];
struct value cost[100005];
int n, m;
stack<int> remaining;

bool compareByC(struct value &x, struct value &y)
{
    return x.c < y.c;
}

bool compareByIndi(struct value &x, struct value &y)
{
    return x.indi < y.indi;
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> cost[i].a;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cost[i].c;
        cost[i].indi = i;
    }
    for (int i = 1; i <= m; ++i)
        cin >> ds[i].type >> ds[i].num_dish;
    sort(cost + 1, cost + 1 + n, compareByC);
    for (int i = n; i >= 1; --i)
        remaining.push(cost[i].indi);
    sort(cost + 1, cost + 1 + n, compareByIndi);
}

ll service(int k, int indi)
{
    ll sum_k = 0;
    if (ds[k].num_dish <= cost[indi].a)
    {
        sum_k += ds[k].num_dish * cost[indi].c;
        cost[indi].a -= ds[k].num_dish;
        ds[k].num_dish = 0;
        return sum_k;
    }
    else
    {
        sum_k += cost[indi].a * cost[indi].c;
        ds[k].num_dish -= cost[indi].a;
        cost[indi].a = 0;

        return sum_k;
    }
}

void service_full(int k)
{
    ll sum_k = 0;
    sum_k += service(k, ds[k].type);
    while (ds[k].num_dish != 0)
    {

        while (cost[remaining.top()].a == 0)
        {
            remaining.pop();
            if (remaining.empty())
            {
                cout << 0 << "\n";
                return;
            }
        }

        sum_k += service(k, remaining.top());
    }
    cout << sum_k << "\n";
}

int main()
{
    input();
    int k = 1;
    while (k <= m)
    {
        if (remaining.empty())
        {
            cout << 0 << "\n";
            k++;
        }
        else
        {
            service_full(k);
            k++;
        }
    }
    return 0;
}