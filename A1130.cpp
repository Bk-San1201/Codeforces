#include <iostream>

using namespace std;
int main()
{
    int n;
    int a[1000];
    cin >> n;
    int cnt_posi = 0;
    int cnt_nega = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            cnt_posi++;
        if (a[i] < 0)
            cnt_nega++;
    }
    int mid = (n % 2 == 0) ? n / 2 : (n / 2 + 1);
    if (cnt_posi >= mid)
        cout << 1;
    else if (cnt_nega >=mid)
        cout << -1;
    else
    {
        cout << 0;
    }
    
}