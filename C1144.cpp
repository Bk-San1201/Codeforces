#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 200001
int n;
int a[N_MAX];
int cnt = 0;
int cnt_max = -1;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
}

void execute()
{
    if (n == 1)
    {
        cout << "YES\n";
        cout << n << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n"
             << 0 << endl << "\n";
            
        return;
    }
    if (a[0] == a[1])
        cnt++;
    if (cnt > cnt_max)
        cnt_max = cnt;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
            cnt++;
        else
            cnt = 0;
        if (cnt > cnt_max)
            cnt_max = cnt;
    }
    if (cnt_max >= 2)
        cout << "NO";
    else if (cnt_max == 0)
    {
        cout << "YES\n";
        cout << n << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n"
             << 0 << "\n\n";
    }
    else
    {
        vector<int> arr_incre;
        vector<int> arr_decre;
        int i;
        for (int i = 0; i < n - 1; i++)
        {
            if(a[i] == a[i+1])
                arr_decre.push_back(a[i]);
        }
        cout << "YES\n";
        int size_incre = n - arr_decre.size();
        cout << size_incre<< endl;
        
        for (int i = 0; i < n; i++)
        {
            if (a[i] != a[i+1])
                cout << a[i] << " ";
            
        }
        cout << endl << arr_decre.size() << endl;
        for (i = arr_decre.size()-1; i >=0 ; i--)
            cout << arr_decre[i] <<" ";
    }
}
int main()
{
    input();
    execute();
    return 0;
}