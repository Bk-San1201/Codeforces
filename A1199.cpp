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
    int n, x, y;
    cin >> n >> x >> y;
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    for (int i = 1; i <= n; i++) {
        bool check = true;
        for (int j = i - 1; j >= i - x; j--) {
            if (j >= 1 && j <= n) {
                if (a[i] >= a[j])
                check = false;
            }
        }
        for (int j = i + 1; j <= i + y; j++) {
            if (j >= 1 && j <= n) {
                if (a[i] >= a[j])
                check = false;
            }
        }
        if (check == true)
            {
                cout << i;
                return 0;
            }
    }
    return 0;
}
