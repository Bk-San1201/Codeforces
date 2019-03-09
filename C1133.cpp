#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
int n;

int main()
{
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    int max1 = -1;
    for (int i = 0; i < n; i++)
        max1 = max(max1, upper_bound(a.begin(), a.end(), a[i] + 5) - i + 1) ;
    cout << max1;
    return 0;
}