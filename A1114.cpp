#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, x, y, z;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if (x > a)
    {
        cout << "NO";
        return 0;
    }
    a -= x;
    if (y > a + b)
    {
        cout << "NO";
        return 0;
    }
    if (y > a)
    {
        y -= a;
        a = 0;
        b -= y;
    }
    else
    {
        a -= y;
    }
    if (z > a + b +c)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
    
}