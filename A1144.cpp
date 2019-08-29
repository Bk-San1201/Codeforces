#include <iostream>
#include <algorithm>
#include <string>

#define MAX_LENGTH 100

using namespace std;

int main()
{
    int dem = 0;
    cin >> dem;
    string s;
    int *a = new int[MAX_LENGTH];
    while (dem--)
    {
        // fflush(stdin);
        cin >> s;
        if (s.size() == 1)
        {
            cout <<"YES\n";
            continue;
        }
        for (int i = 0; i < s.size(); i++)
            a[i] = s[i];
        sort(a, a + s.size());
        int i = 0;
        if (a[i] +1 != a[i+1])
        {
            cout << "NO\n";
            continue;
        }
        for (i = 1; i < s.size(); i++)
        {
            if (a[i-1] + 1 != a[i])
            {
                cout << "No\n";
                break;
            }
        }
        if (i == s.size())
            cout << "Yes\n";
    }
    
}