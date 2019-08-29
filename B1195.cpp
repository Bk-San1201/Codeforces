#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long

int main() 
{
    ll n, k;
    cin >> n >> k;

    ll tmp = n + k;
    tmp *= 2;
    ll delta = (ll) sqrt(9 + 4 * tmp);
    // cout << delta << endl;
    ll x = (3 + delta) / 2;
    // cout << x << endl;
    cout << n - x + 3;


    return 0;
}