#include <iostream>
#define ll long long
using namespace std;
int n; ll sum=0;
void Do() {
    cin>>n;
    for (int i=2; i<=n/2;i++) {
        ll k = i*2;
        while (k<=n) {
            sum+=k/i;
            k+=i;
        }
    }
}
int main() {
    Do();
    cout<<sum*4;
}