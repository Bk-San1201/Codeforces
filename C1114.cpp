#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define ull unsigned long long

ull v_p(ull n, ull p)
{
    ull p_temp = p;
    ull ans = 0;
    while (n > 0)
    {
        ans += (n /= p);
    }
    return ans;
}

vector<pair<ull, ull>> factorize(ull b)
{
    vector<pair<ull, ull>> a;
    for (ull i = 2; i * i <= b; i++)
    {
        pair<int, ull> temp;
        temp.first = 0;
        if (b % i == 0)
            temp.second = i;
        while (b % i == 0)
        {
            ++temp.first;
            b /= i;
        }
        if (temp.first != 0)
            a.push_back(temp);
    }
    if (b == 1)
        return a;
    pair<int, ull> temp;
    temp.first = 1;
    temp.second = b;
    a.push_back(temp);
    return a;
}

int main()
{
    ull n;
    ull b;
    ull min = 1e18;
    cin >> n >> b;
    vector<pair<ull, ull>> factor_b = factorize(b);
    for (vector<pair<ull, ull>>::iterator it = factor_b.begin(); it != factor_b.end(); ++it)
    {
        ull ans = v_p(n, it->second);
        // cout << it->first << " " << it->second << " " << ans << endl;

        if (min > ans / it->first)
            min = ans / it->first;
    }
    cout << min;

    return 0;
}
