#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#define ll long long
#define NMAX 100005
#define N 100000
struct Robot
{
    int x, y;
    int f1, f2, f3, f4;
};
int n;
Robot a[NMAX];
int areaX[4];
int areaY[4];

void exe()
{
    areaX[0] = (-1) * N;
    areaY[0] = (-1) * N;
    areaX[1] = N;
    areaY[1] = (-1) * N;
    areaX[2] = N;
    areaY[2] = N;
    areaX[3] = (-1) * N;
    areaY[3] = N;
    for (int i = 0; i < n; i++)
    {
        if (a[i].f1 == 0 && a[i].x > areaX[0])
        {
            areaX[0] = a[i].x;
            areaX[3] = a[i].x;
        }
        if (a[i].f2 == 0 && a[i].y < areaY[2])
        {
            areaY[2] = a[i].y;
            areaY[3] = a[i].y;
        }
        if (a[i].f3 == 0 && a[i].x < areaX[2])
        {
            areaX[2] = a[i].x;
            areaX[1] = a[i].x;
        }
        if (a[i].f4 == 0 && a[i].y > areaY[0])
        {
            areaY[0] = a[i].y;
            areaY[1] = a[i].y;
        }
    }

}
int main() 
{
    freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    for (int tc = 0; tc < q; tc++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y;
            cin >> a[i].f1 >> a[i].f2;
            cin >> a[i].f3 >> a[i].f4;
        }
        exe();
        if (areaX[0] <= areaX[2] && areaY[0] <= areaY[2])
        {
            cout << 1 << " " << areaX[0] << " " << areaY[0] << endl;
        }
        else 
        cout << 0 << endl;
    }


    return 0;
}
