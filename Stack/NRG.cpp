
#include <bits/stdc++.h>
using namespace std;

int main(){
    stack <int> s;
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        s.push(x);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    


}