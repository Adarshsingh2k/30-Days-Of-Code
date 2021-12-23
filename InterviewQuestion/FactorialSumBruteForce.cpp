/*  Factorial Sum */

#include <bits/stdc++.h>
using namespace std;

int fact(int n){

    if(n==0) return 1;

    return n* fact(n-1);

}


int factSum(int n){

    if(n==0) return 1;
    int sum=1;
    for(int i=1;i<=n;i++) sum+=fact(i);

    return sum;

}


int main() {
    int n;
    cin>>n;
    cout<<"Factorial Sum is = "<< factSum(n);
}
