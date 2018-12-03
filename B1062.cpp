#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
vector<int> Nhantu;
vector<int> Power;

void Phantichthuaso(int k) {
    Nhantu.push_back(1);
    Power.push_back(0);
    int i=2; int j=0;
    while(k != 1) {
        if (k%i==0) {
            k = k/i;
            if (i != Nhantu[j]) {
                Nhantu.push_back(i);
                Power.push_back(1);
                j++;
            } else {
                Power[j]++;
            }
        }
        else {
            i++;
        }
    }
}

int main() {
    cin>>n; int tich=1;
    Phantichthuaso(n);
    for (int i=0;i<Nhantu.size(); i++) {
        tich*=Nhantu[i];
    }
    cout<<tich<<" ";
    int dem=0;
    for (int i=1; i<Power.size();i++) {
        while(Power[i] > pow(2,dem)) dem++;
    }
    bool check = true;
    for (int i=1; i<Power.size(); i++) {
        if (Power[i] != pow(2,dem)) {
            check = false; 
            break;
        }
    }
    if (check) cout<<dem;
    else cout<<dem+1;
    

    return 0;
}