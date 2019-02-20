#include <iostream>

using namespace std;

int main()
{
    int b, k;
    int a[100005];
    int cnt_odd = 0, cnt_even = 0;
    ios_base::sync_with_stdio(false);
    cin >> b >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        if (a[i] % 2)
            cnt_odd++;
        else
            cnt_even++;
    }
    if (b % 2 == 0)
    {
        if (a[k - 1] % 2 == 1)
        {
            cout << "odd";
            return 0;
        }
        else
        {
            cout << "even";
            return 0;
        }
    }
    else
    {
        if(cnt_odd %2 ==0)
        {
            cout << "even";

        }
        else 
        {
            cout << "odd";
        }
    }
    return 0;
}