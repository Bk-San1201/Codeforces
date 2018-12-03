#include <iostream>
#include <algorithm>
#include <string>


#define ll long long int
ll NUM=1e9+7;
using namespace std;

ll n,q; 
char s[100100];
ll arr[100100];
ll sum[100100];

struct interval {
    ll l;
    ll r;
};
struct interval q_array[100009];
void Input() {
    cin>>n>>q;
    cin>>s;
    for(int i=0; i<n;i++) {
        arr[i+1] = s[i]=='1'? 1:0;
        sum[i+1] = sum[i] +(s[i] -48);
    }
    for(int i=1;i<=q;i++) {
        cin>>q_array[i].l>>q_array[i].r;}
    
 
}
ll pow(ll a, ll n)
{
    if(n==0) return 1;
    if(n == 1) {
        return a;
    } else { 
        ll temp = pow(a, n/2);
        if(n % 2 == 0)
            return (temp*temp)%NUM;
        else
            return ((temp*temp%NUM)*a)%NUM;
    }
}


void Do(ll l, ll r) {
    ll one = sum[r] -sum[l]+arr[l];
    ll zero = r -l+1-one;
    ll ans1 = pow(2,one);
    ll ans2 = pow(2,zero);
    ll ans = (ans1-1)*ans2%NUM;
    cout<<ans<<"\n";

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Input();
 
    for(int i=1;i<=q;i++) {
 //       cin>>q_array[i].l>>q_array[i].r;
        
        Do(q_array[i].l,q_array[i].r);
    }
    return 0;
}