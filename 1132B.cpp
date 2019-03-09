#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

#define ll long long
int n,m ;
    ll a[300001] ;
    int q[300001] ;
    vector<ll> Sum ;
    vector<ll> res;
int main()
{
    

    cin>>n ;

    for (int i = 0; i<n; i++)
    {
        cin >> a[i] ;
    }

    cin >>m;

    for (int i= 0; i<m; i++)
    {
        cin >> q[i] ;
    }

    sort(a, a+n) ;

    Sum.push_back(a[0]) ;

    for (int i= 1; i<n; i++)
    {
        Sum.push_back(Sum[i-1] + a[i]) ;
    }

    for (int i= 0; i<m; i++)
    {
        cout<<Sum[n-1] - Sum[q[i] - 1]<<"\n" ;
    }

    return 0;

}