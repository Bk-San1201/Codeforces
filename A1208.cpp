#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005

int main()
{
    // freopen("input.txt", "r", stdin);
    int T;
    int a, b, n;
    int tmp;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> n;
        tmp = a ^ b;
        if (n % 3 == 0)
        {
            cout << a << endl;
        }
        else if (n % 3 == 1)
            cout << b << endl;
        else
        {
            cout << tmp << endl;
        }
    }
    return 0;
}
