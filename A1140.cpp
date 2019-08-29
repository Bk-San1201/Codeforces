#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int arr[10000];
    bool read[10000];
    int cnt = 0;
    int temp = 0;
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        read[i] = false;
    }
    int max_temp = arr[0];
    while (temp != n)
    {
        for (int i = temp; i < n; i++) {
            max_temp = max(max_temp, arr[i]);
            if (i+1 == max_temp)
            {
                temp = i + 1;
                cnt++;
                break;
            }            
        }
    
    }
    cout << cnt;
}