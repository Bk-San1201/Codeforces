#include <iostream>
#include <algorithm>

using namespace std;

int q, n, k;
int a[101];

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int execute()
{
    sort(a, a + n);
    if (a[n-1] <= k)
        return a[0] + k;
    if (a[0] + k >= a[n - 1])
    {
        return a[0] + k;
    }
    else if (a[0] + k >= a[n - 1] - k)
    {
        return a[0] + k;
    }
    else
    {
        return -1;
    }
}
int main()
{
    cin >> q;
    while (q--)
    {
        input();
        cout << execute() << endl;
    }
}