#include <iostream>
#include <vector>
using namespace std;
struct UnionFind {
    int value;
    int rank = 1;
    bool check = true;
};
struct UnionFind a[150];
int n; int ans = 0;

void input() {
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i].value;
    }
}

void Update() {
    for (int i = 0; i <n; i++) {
        if (a[i].check) {
            for (int j = i+1; j<n;j++) {
                if (a[j].value==a[i].value+(j-i)) {
                    a[i].rank+=1;
                    a[j].check = false;
                }
            }
        }
    }
}
void OutAns() {
    for (int i = 0; i<n; i++) {
        if (a[i].check) {
            if (a[i].value==1) {
                if (a[i].rank ==1000 && a[i].rank > ans)  ans = a[i].rank;
                else if (a[i].rank-1 > ans) ans = a[i].rank-1;
            }
            else if (1000-a[i].value+1==a[i].rank && a[i].rank-1 >ans) ans= a[i].rank-1;
            else if (a[i].rank-2>ans) ans = a[i].rank-2;

        }

    }

}

int main() {
    input();
    Update();
    OutAns();
    cout<<ans;
}