#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005
int main()
{
    int n;
    cin >> n;
    int a[N][2];
    int per1 = 1, per2 = 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
            a[i][j] = -1;
    }
    int temp;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> temp;
        if (a[temp][0] == -1)
            a[temp][0] = i;
        else
            a[temp][1] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        // sum += min(abs(a[i][0] - per1) + abs(a[i][1] - per2), );
        if (abs(a[i][0] - per1) + abs(a[i][1] - per2) < abs(a[i][1] - per1) + abs(a[i][0] - per2))
        {
            sum += abs(a[i][0] - per1) + abs(a[i][1] - per2);
            per1 = a[i][0];
            per2 = a[i][1];
        }
        else
        {
            sum += abs(a[i][1] - per1) + abs(a[i][0] - per2);
            per1 = a[i][1];
            per2 = a[i][0];
        }
        
    }
    cout << sum;
}