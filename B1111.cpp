#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
// #include <stdio.h>

using namespace std;

vector<double> ds;
double n, k;
double m;
double TBC;
double _max;

bool comparePair(double a, double b)
{
    return a > b;
}

void input()
{
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        // temp.first = true;
        ds.push_back(temp);
    }
    sort(ds.begin(), ds.end(), comparePair);
    double t = 0.00;
    for (int i = 0; i < n; i++)
    {
        t += ds[i];
    }
    TBC = t / n;
    _max = TBC;
}

void _do()
{
    double n_temp = n;
    double m_temp = m;
    for (int i = 0; i <= min(m_temp, n_temp-1); ++i)
    {
        if (_max < TBC + min(n*k,m)/n)
        {
            _max = TBC + min(n*k,m)/n;
        }
        TBC = (TBC*n - ds.back())/ (n-1);
        ds.pop_back();
        n -= 1;
        m -= 1;
    }

    cout.precision(10);
    cout << _max;
}

int main()
{
    input();
    _do();

    return 0;
}