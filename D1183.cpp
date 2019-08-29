#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 200005
int q, n;
int a[MAX];
int b[MAX];
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a[temp] += 1;
    }
    sort(a + 1, a + n + 1);
}
int execute2()
{
    int indi = n;
    int res = 0;
    int cur = a[n];
    while (cur >= 1 && indi > 0)
    {
        res += min(cur, a[indi]);
        if (cur > a[indi])
            cur = a[indi] - 1;
        else
            cur -= 1;
        indi -= 1;
    }
    return res;
}

int main()
{
    cin >> q;
    while (q--)
    {
        input();
        cout << execute2() << endl;
    }
}