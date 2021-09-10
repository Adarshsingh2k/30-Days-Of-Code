#include <bits/stdc++.h>
using namespace std;

int cnt_setBits(int n){
    //return __builtin_popcount (n);

    int count=0;

    if(n==1 or  n== -1 )return 1;
    //if(n==pow(2,n))return 1;

    while(n){
        n&=n-1;
        count++;
    }

    return count;
}

int main() {
    int a,b;
    cin>>a>>b;
    int prod=a*b;
    cout<<cnt_setBits(prod);
    
}
