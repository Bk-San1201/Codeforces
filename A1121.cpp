#include <iostream>
#include <algorithm>

using namespace std;

#define NMAX 100

struct student
{
    int power;
    int school;
    int indi;
    // counter show the level power in its school
    int counter;
};

bool myCompare(struct student &a, struct student &b)
{
    return a.power > b.power;
}

void input(int *n, int *m, int *k, struct student *st, pair<int,int> *c)
{
    cin >> *n >> *m >> *k;
    for (int i = 0; i < *n; i++)
    {
        cin >> st[i].power;
        st[i].indi = i + 1;
    }

    for (int i = 0; i < *n; i++)
        cin >> st[i].school;
    for (int i = 0; i < *k; i++)
    {
        cin >> c[i].first;
        c[i].second = st[c[i].first - 1].power;
    }
        
}

bool checkIn(pair<int,int> *c, int k, int power)
{
    for (int i = 0; i < k; i++)
        if (c[i].second == power)
            return true;
    return false;
}
int execute(int n, int m, int k, struct student *st, pair<int,int> *c, int *cntSchool)
{
    sort(st, st + n, myCompare);
    for (int i = 1; i <= m; i++)
        cntSchool[i] = 0;
    for (int i = 0; i < n; i++)
        st[i].counter = (cntSchool[st[i].school] == 0) ? (cntSchool[st[i].school]++) : 1;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkIn(c, k, st[i].power))
        {
            res += st[i].counter;
        }
        
    }
    return res;
}

int main()
{
    // An array of pairs. First element is pow, the other is school.
    struct student st[NMAX];
    int n, m, k;
    pair<int, int> c[NMAX];
    int cntSchool[NMAX];
    input(&n, &m, &k, st, c);
    cout << execute(n, m, k, st, c, cntSchool);
    return 0;
}