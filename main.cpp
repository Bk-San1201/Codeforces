#include <bits/stdc++.h>

using namespace std;

#define vctc vector<char>

int *factorial_12(){
    int a[14] ;
    a[0] = 1;

    for (int i = 1; i<14 ;i++){
        a[i] = i*a[i-1] ;
    }

    int *b ;
    b = &a[0] ;
    return b;
}

vctc Plus(vctc a, vctc b){
    int a_sz = a.size() - 1 ;
    int b_sz = b.size() - 1 ;

    int mx_sz = max(a_sz,b_sz) ;
    vctc res;

    int cnt = 0;
    int carry = 0;

    while(cnt <= mx_sz){
        int temp = (cnt <= a_sz)*((int)(a[a_sz-cnt])-48) + (cnt <= b_sz)*((int)(b[b_sz-cnt])-48)  + carry ;      
        carry = temp/10 ;

        char x = (temp%10 + 48);
        // cout<<x<<"\n" ;
        res.push_back(x) ;

        cnt++;
    }

    if(carry == 1) res.push_back('1');

    reverse(res.begin(), res.end()) ;

    return res;
}

// ex : 1233 * 2
vctc multiple_digit(vctc a, char c){
    vctc res;
    if (c == '0') {
        for(int i = 0; i<a.size() ;i++){
            res.push_back('0') ;
        }
    }
    else{
        int b = (int)(c) - 48 ;

        int cnt = a.size() - 1 ;
        int carry = 0;

        while(cnt >= 0){
            int temp = (int)(a[cnt] - 48)*b + carry ;
            carry = temp/10 ;

            char x = (temp%10 + 48) ;
            res.push_back(x) ;

            cnt--;
        }

        if(carry != 0) res.push_back((int)(carry + 48));

        reverse(res.begin(), res.end()) ;
    }
    return res;
}

// ex: 123 * 3123
vctc multiple(vctc a, vctc b){
    vector<vctc> res;
    res.push_back(multiple_digit(a,b[b.size() - 1])) ;

    for(unsigned int i = 1; i < b.size() ;i++){
        vctc temp = multiple_digit(a,b[b.size() - 1 - i]) ;

        for (int j = 0; j<i ;j++){
            temp.push_back('0') ;
        }

        res.push_back(Plus(res[i-1], temp)) ;
    }

    return res[res.size() - 1] ;
}

// Complete the extraLongFactorials function below.
void extraLongFactorials(int m) {
    int n = m+1;
    vector<vctc> res;
    vctc t ;
    string T = to_string(factorial_12()[12]) ;

    for(unsigned int j =0; j< T.size(); j++) t.push_back(T[j]) ;
    res.push_back(t) ;

    for (int i = 13; i < n; i++){
        vctc temp ;
        string Temp = to_string(i) ;

        for(unsigned int j =0; j< Temp.size(); j++) temp.push_back(Temp[j]) ;
        res.push_back(multiple(res[i-13],temp));
    }

    for (unsigned int i =0; i<res[res.size()-1].size();i++){
        cout<<res[res.size()-1][i] ;
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(n<12) cout<<factorial_12()[n] ;
    else{
    extraLongFactorials(n);
    //     vector<char> a = {'1','0','2','9','0'} ;
    //     vector<char> b = {'1','0'} ;
    //     vector<char> res;
    //     res = multiple(a,b) ;

    //     for (unsigned int i = 0; i<res.size();i++) {
    //         cout<<res[i]<<" ";
    //     }
    }
    return 0;
}