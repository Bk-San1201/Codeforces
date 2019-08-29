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
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    int b, p, f;
    int h, c;
    while (T--)
    {
        cin >> b >> p >> f;
        cin >> h >> c;
        if (2 * p + 2 * f <= b)
        {
            cout << h * p + c * f << endl;
            continue;
        }
        if (h >= c)
        {
            int sum = 0;
            if (2 * p <= b)
            {
                sum += p * h;
                b -= 2 * p;
                sum += min(b / 2, f) * c;
            }
            else
            {
                sum += (b / 2) * h;
            }
            cout << sum << endl;
        }
        else
        {
            int sum = 0;
            if (2 * f <= b)
            {
                sum += f * c;
                b -= 2 * f;
                sum += min(b / 2, p) * h;
            }
            else
            {
                sum += (b / 2) * c;
            }
            cout << sum << endl;
        }
    }
    return 0;
}
