#include <iostream>
#include <math.h>
using namespace std;

int fitness(int a[], int n, int tbc)
{
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        if (abs(a[i] - tbc) > 1)
        {
            s += a[i] > tbc ? (a[i] - tbc - 1) : (tbc - a[i] - 1);
        }
    }
    return s;
}
int main()
{
    int a[1000];
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int t,s;
    int cost = 100005;
    for (int i = 1; i < 101; ++i)
    {
        s = fitness(a,n,i);
        if (cost > s)
        {
            cost = s;
            t = i;
        }

    }
    cout<<t<<" "<<cost;
    
    return 0;
}