#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;

void input()
{
    cin >> n;
    cin.ignore();
    getline(cin, s);
    // cout << s;
}

void execute()
{
    if (n == 1 || s[0] == '>' || s[s.length()-1] == '<')
    {
        // cout << 
        cout << 0 << "\n";
        return;
    }
    int min1 = 0, min2 = 0;
    int i = 0;
    while (s[i] == '<')
    {
        min1++;
        i++;
    }
    i = s.length() - 1;
    while (s[i] == '>')
    {
        min2++;
        i--;
    }
    cout << min(min1, min2) << "\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        input();
        execute();
    }
    return 0;
}