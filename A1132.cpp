#include <iostream>

using namespace std;
#define ll long long
int main()
{
    ll a[4];
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    if (a[0] == 0 && a[2]!=0)
    {
        cout << 0;
        return 0;
    }
        
    if (a[0] == a[3])
        cout << 1;
    else
        cout << 0;
}