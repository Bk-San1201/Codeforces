#include <iostream>

using namespace std;
#define ll long long
ll ans[1000001];
void cal(ll *a)
{
    a[1] = 0;
    ans[1] = 0;
    for (int i = 2; i <= 1000001; i++)
    {
        if (i % 2 == 0)
        {
            a[i] = a[i / 2] + 1;
        }
        else
        {
            a[i] = a[(i + 1) / 2] + 2;
        }
        ans[i] = ans[i-1] +  a[i];
    }
}
// ll execute(int &n1, int &n2, ll *a)
// {

//     ll res = 0;
//     for (int i = n1; i <= n2; i++)
//     {
//         res += a[i];
//     }
//     // delete a;
//     return res;
// }
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n1, n2, T;
    scanf("%d", &T);
    ll *a = new ll[1000001];
    cal(a);
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d", &n1, &n2);
        printf("Case #%d\n%ld\n", i + 1, ans[n2] - ans[n1 - 1]);
        
    }
    // for (int i = 1; i < 100; i++)
    // {
    //     cout << "So " << i << ": " << a[i] << endl;
    // }
    return 0;
}