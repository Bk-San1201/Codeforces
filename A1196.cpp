#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long

int main() 
{
    freopen("input.txt", "r", stdin);
    int T;
    ll a, b, c;
    cin >> T;
    for (int tc = 0; tc < T; tc++) 
    {
        cin >> a >> b >> c;
        ll sum = a + b + c;
        cout << sum /2  << endl;
    }
    return 0;
}
