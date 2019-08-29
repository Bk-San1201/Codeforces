#include <iostream>

using namespace std;

int first_run(int i, int n)
{
    if (i == n)
        return 1;
    else
        return i + 1;
}
int second_run(int i, int n)
{
    if (i == 1)
        return n;
    else
        return i - 1;
}

int main()
{
    int n, a, b, x, y;
    cin >> n >> a >> x >> b >> y;
    while (1)
    {
        a = first_run(a, n);
        b = second_run(b, n);
        if (a == b)
        {
            cout << "YES";
            return 0;
        }
        else if (a == x)
        {
            cout << "NO";
            return 0;
        }
        else if (b == y)
        {
            cout << "NO";
            return 0;
        }
        else
        {
            continue;
        }
    }
}