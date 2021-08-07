// To check if a string is a Pangram or not

#include <bits/stdc++.h>
using namespace std;
int main() {

    map<char,int>m;

    string str;

    getline(cin,str);

    int n=str.length();

    if(n<26){
        cout<<"Not a Pnagram";
        return 0;
    }

    for(int i=0;i<n;i++){
        m[str[i]]++;

    }
    for(auto x:m){
        if(x.second==0){
            cout<<"Not a pangram";return 0;
        }
        else cout<<"Panagram string"; return 0;
    }
  
   
    

}
