#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
int arr[1001];
int drink[1001];
int res = 0;

bool mysort(int &a, int &b) 
{
    return a > b;
}
int main()
{
    int n, k;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        drink[arr[i]] += 1;
    }
    sort(drink + 1, drink + 1 + k, mysort);
    int numOfSets = (int)ceil(1.0 * n / 2);
    int i = 1;
    while ((numOfSets - (int)ceil(1.0 * drink[i] / 2) >= 0))
    {
        numOfSets -= (int)ceil(1.0 * drink[i] / 2);
        res += drink[i];
        i += 1;
        
    }
    if (numOfSets == 0)
        cout << res;
    else
        cout << res + numOfSets * 2;

    return 0;
}