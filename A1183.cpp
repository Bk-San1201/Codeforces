#include <iostream>

using namespace std;

int cal(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;

    }
    return sum;
}
int main()

{
    int n;
    int sum = 0;
    cin >> n;
    while (cal(n) % 4 != 0)
        n++;
    cout << n;
}