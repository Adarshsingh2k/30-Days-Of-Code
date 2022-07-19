#include<bits/stdc++.h>
using namespace std;

string solve(string s,int k){
    string ans="";
    
    while(s.length()>0){
        char temp=s[0];
        for(int i=1;i<k and i<s.length();i++){
            if(s[i]<temp) temp=s[i];
        }
        ans=ans+temp;
        for(int i=0;i<k;i++){
            if(s[i]==temp) {s.erase(s.begin()+i); break;}}
    }
    return ans;

}

int main(){
    string s;
    int k;
    cin>>s>>k;
    cout<<solve(s,k);
}