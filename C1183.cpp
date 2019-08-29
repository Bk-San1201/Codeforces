#include <iostream>

using namespace std;
#define ll long long
ll q, k, n, a, b;

void input()
{
    cin >> k >> n;
    cin >> a >> b;
}

ll execute()
{
    if (n * b >= k)
        return -1;
    else
    {
        ll temp = k - n * b;
        ll res = temp / (a - b);
        if (res > n)
            return n;
        if (temp % (a - b) == 0)
            return res - 1;
        
        return res;
    }
}
int main()
{
    cin >> q;
    while (q--)
    {
        input();
        cout << execute() << endl;

    }
}