#include <iostream>
#include <algorithm>

using namespace std;

struct troupe
{
    bool clown;
    bool acrobat;
    int indi;
};
int n;
struct troupe trp[5000];
void input()
{
    cin >> n;
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); ++i)
    {
        trp[i].clown = a[i] - '0';
        trp[i].acrobat = b[i] - '0';
        trp[i].indi = i + 1;
    }
}
int main()
{
    return 0;
}