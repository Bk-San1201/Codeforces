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
    int *a = new int[NMAX];
    int n;
    ll sum = 0;
    ll maxtmp = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (maxtmp < a[i])
            maxtmp = a[i];
    }
    if (sum % 2 == 0 && maxtmp <= sum / 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

