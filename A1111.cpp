#include <iostream>
#include <string>

using namespace std;

bool check1(char m)
{
    if (m == 'u')
        return true;
    if (m == 'e')
        return true;
    if (m == 'o')
        return true;
    if (m == 'a')
        return true;
    if (m == 'i')
        return true;
    return false;
}
bool check2(char m, char n)
{
    if (check1(m) && check1(n))
        return true;
    if (!check1(m) && !check1(n))
        return true;
    return false;
}

void _do()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if (s.length() != t.length())
    {
        cout << "No";
        return;
    }
    else
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (!check2(s[i], t[i]))
            {
                cout << "No";
                return;
            }
        }
        cout << "Yes";
        return ;
    }
}

int main()
{
    _do();
    return 0;
}