#include <iostream>
#include <vector>
using namespace std;
struct Element {
    int a;
    int par;
    int rank;
};

struct Element A[100000];
int n; int q;

void Input() {
    cin>>n>>q;
    A[1].a = 1; A[1].par = 1; A[1].rank = 0;
    for (int i=2; i<=n; i++) {
        cin>>A[i].par;
    }
// Update Rank
    
}