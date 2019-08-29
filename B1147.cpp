#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long

bool check(ll i, ll j)
{
    return (i + j) % 2 == 1;
}
void print(ll *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    ll *a = new ll[n];
    ll *odd_a = new ll[n];
    ll *even_a = new ll[n];
    int odd = 0, even = 0, j = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2)
        {
            odd++;
            odd_a[j] = a[i];
            j++;
        }
        else
        {
            even++;
            even_a[k] = a[i];
            k++;
        }
    }
    if (odd == 0 || even == 0)
        print(a, n);
    if (odd == even)
    {
        sort(a, a + n);
        print(a, n);
    }
    if (odd < even)
    {
        sort(odd_a, odd_a + odd);
        int *k = new int[even];
        for (int i = 0; i < odd; i++)
        {
            int min = a[i];
            int min_indi = i;
            for (int j = i + 1; j < even; j++)
            {
                if (min > a[j])
                {
                    min = a[j];
                    min_indi = j;
                }
            }
            swap(even_a[i], even_a[min_indi]);
        }
        int i = 0, j = 0;
        for (int k = 0; k < n; k++)
        {
            if (odd_a[i] < even_a[j])
            {
                cout << odd_a[i] <<" ";
                i++;
            }
                
            else
            {
                cout << even_a[j] << " ";
                j++;
            }
            
        }
    }
    else
    {
        sort(even_a, even_a + even);
        // int *k = new int[even];
        for (int i = 0; i < even; i++)
        {
            int min = a[i];
            int min_indi = i;
            for (int j = i + 1; j < odd; j++)
            {
                if (min > a[j])
                {
                    min = a[j];
                    min_indi = j;
                }
            }
            swap(odd_a[i], odd_a[min_indi]);
        }
        int i = 0, j = 0;
        for (int k = 0; k < n; k++)
        {
            if (odd_a[i] < even_a[j])
            {
                cout << odd_a[i] <<" ";
                i++;
            }
                
            else
            {
                cout << even_a[j] << " ";
                j++;
            }
            
        }
    }
    
}