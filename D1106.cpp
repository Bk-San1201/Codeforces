#include <iostream>
#include <vector>
// #include <algorithm>
#include <queue>

using namespace std;

struct list_node
{
    // int indi;
    vector<int> adjacent;
};

struct list_node ds[100005];
int n, m;
bool visited[100005];
priority_queue<int, vector<int>, greater<int>> list_sort;
vector<int> truyvan;

// bool compareSort(int a, int b)
// {
//     return a > b;
// }

void input()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int temp1, temp2;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        ds[temp1].adjacent.push_back(temp2);
        ds[temp2].adjacent.push_back(temp1);
    }
}

void dfs()
{
    list_sort.push(1);
    visited[1] = true;
    while (!list_sort.empty())
    {
        int x = list_sort.top();
        list_sort.pop();
        truyvan.push_back(x);

        for (int i = 0; i < ds[x].adjacent.size(); ++i)
        {
            if (!visited[ds[x].adjacent[i]])

            {

                list_sort.push(ds[x].adjacent[i]);
                visited[ds[x].adjacent[i]] = true;
            }
        }
    }
}
int main()
{
    input();
    dfs();
    for (int i = 0; i < truyvan.size(); ++i)
    {
        cout << truyvan[i] << " ";
    }
    return 0;
}