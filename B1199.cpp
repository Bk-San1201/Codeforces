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
    freopen("input.txt", "r", stdin);
    int H, L;
    cin >> H >> L;
    double h = 1.0 * H;
    double l = 1.0 * L;
    double res = 0;
    res = l * l;
    res -= h * h;
    
    res /= (2 * h);
    cout.precision(17);
    cout << res;
    return 0;
}
