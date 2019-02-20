#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n;
vector<string> ds;

void input()
{
    cin >> n;
    // fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        ds.push_back(s);
    }
    return;
}

int check_string(int i, int j)
{
    if (ds[i][j] != 'X')
        return 0;
    if (ds[i - 1][j - 1] != 'X')
        return 0;
    if (ds[i - 1][j + 1] != 'X')
        return 0;
    if (ds[i + 1][j - 1] != 'X')
        return 0;
    if (ds[i + 1][j + 1] != 'X')
        return 0;
    return 1;
}

void doA()
{
    int sum = 0;
    if (n <= 2)
    {
        cout << sum;
        return;
    }
    // int sum = 0;
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++)
        {
            sum+=check_string(i,j);
        }
    cout << sum;
}

int main()
{
    input();
    doA();
    return 0;
}