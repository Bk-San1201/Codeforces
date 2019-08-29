#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005
ll n;
int h1[NMAX], h2[NMAX];
ll pick_one[NMAX], pick_two[NMAX];

// void dp()
// {

// }

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> h2[i];
    }
    ll tmp1 = 0, tmp2 = 0;

    pick_one[0] = h1[0];
    pick_two[0] = h2[0];
    pick_one[1] = h2[0]  + h1[1];
    pick_two[1] = h2[1] + h1[0];
    for (int i = 2; i < n; i++) {
        pick_one[i] = max ( max(pick_two[i - 1], pick_one[i - 2]), pick_two[i - 2]) + h1[i];
        pick_two[i] = max ( max(pick_one[i - 1], pick_two[i - 2]), pick_one[i - 2]) + h2[i];
    }
    // cout << tmp1 << " " << tmp2 << endl;
    cout << ((pick_one[n - 1] > pick_two[n - 1]) ? pick_one[n - 1] : pick_two[n - 1]);

    return 0;
}