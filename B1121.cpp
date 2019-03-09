#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
#define NMAX 1000
int temp[NMAX * NMAX];
int main()
{
    int n;
    int a[NMAX];
    
    int k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            temp[k] = a[i] + a[j];
            k++;
        }
    sort(temp, temp + n * (n - 1) / 2);
    int cnt = 1;
    int max_cnt = 0;
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        if (temp[i] == temp[i+1])
            cnt++;
        else
        {
            if (cnt > max_cnt)
                max_cnt = cnt;
            cnt = 1;
        }
        
    }
    cout << max_cnt;
    
        

}