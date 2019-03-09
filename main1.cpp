#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    clock_t start = clock();
    int a[100000];
    int b[100000];
    int c[100000];
    for (int i = 0; i < 100000; i++)
    {
        b[i] = i;
        c[i] = i + 1;
    }
    for (int i = 0; i < 100000; i++)
        a[i] = b[i] * c[i];
    clock_t finish = clock(); // ham đếm thời gian kết thúc
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\n\n\n";
    printf("Thoi gian thuc thi: %.8lf", duration);
    return 0;
}