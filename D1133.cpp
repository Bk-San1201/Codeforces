#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct tp
{
    int a;
    int b;
    float b1;
    double x;
    int dau;
    int d;
};

int n;
struct tp arr[200005];
int res;
int cnt = 0;
int cnt_sai = 0;
int cnt_b = 0;
bool myComparator(struct tp &k, struct tp &h)
{
    if (k.a == h.a)
        return k.b < h.b;
    return k.a < h.a;
}
void input()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].a;
    for (int i = 0; i < n; i++)
        cin >> arr[i].b;
    for (int i = 0; i < n; i++)
    {
        // cin >> arr[i].a >> arr[i].b;
        if (arr[i].a != 0 && arr[i].b == 0) 
            cnt_b++;
        if (arr[i].a == 0 && arr[i].b != 0)
        {
            cnt_sai++;
        }
        if (arr[i].a == 0 && arr[i].b == 0)
        {
            cnt++;
            continue;
        }
        if (arr[i].a == 0 || arr[i].b == 0)
        {
            continue;
        }
        int temp = __gcd(arr[i].a, arr[i].b);
        arr[i].a /= temp;
        arr[i].b /= temp;
        if (arr[i].a < 0 && arr[i].b > 0)
        {
            arr[i].a *= -1;
            arr[i].b *= -1;
        }
        if (arr[i].a < 0 && arr[i].b < 0)
        {
            arr[i].a *= -1;
            arr[i].b *= -1;
        }
    }
}
void execute()
{
    int max = -1;
    int temp_max = 1;
    sort(arr, arr + n, myComparator);
    for (int i = 0; i < n; i++)
    {
        if (arr[i].a == 0)
            continue;
        if (arr[i].a == arr[i + 1].a && arr[i].b == arr[i + 1].b)
        {
            temp_max++;
        }
        else
        {
            if (max < temp_max)
                max = temp_max;
            temp_max = 1;
        }
    }
    if (max < temp_max)
        max = temp_max;
    temp_max = 1;
    if (max < cnt_b)
        max = cnt_b;
    cout << cnt + max;
}

int main()
{
    input();
    if (cnt == n)
    {
        cout << n;
        return 0;
    }

    if (cnt_sai == n)
    {
        cout << 0;
        return 0;
    }
    // cout << 0;
    execute();
    return 0;
}