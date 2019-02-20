#include <iostream>

using namespace std;

int n;
int a[200005];
long long sum_even = 0;
long long sum_odd = 0;
long long tempofsum_even;
long long tempofsum_odd;
long long run_even;
long long run_odd;

bool check(int i)
{
    bool ans;
    tempofsum_odd = run_odd + sum_even - run_even - ((i % 2 == 0) ? a[i] : 0);
    tempofsum_even = run_even + sum_odd - run_odd - ((i % 2 == 1) ? a[i] : 0);
    if (tempofsum_even == tempofsum_odd)
        ans = true;
    else

        ans = false;
    if (i % 2)
        run_odd += a[i];
    else
        run_even += a[i];
    return ans;
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i % 2)
            sum_odd += a[i];
        else
            sum_even += a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (check(i))
            sum++;
    cout << sum;
    return 0;
}