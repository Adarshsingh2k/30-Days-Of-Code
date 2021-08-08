#include <iostream>
using namespace std;

int main() {
    //cout<<"Hello World!";

    string s;
    cin>>s;

    int n=s.size();
    int cnt=0;
    string str;
    for(int i=0;i<n;i++){
        if(s[i]!='a')
        {
            str.push_back(s[i]);
        }
        if(s[i]=='a') cnt++;
    }
   

    int si=str.size()/2;

    /* cout<<si<<endl;

    cout<<cnt<<endl;
    cout<<str<<endl; */
 if(cnt==0) cout<<"-1"<<endl;

 else{
      for(int i=0;i<n-si;i++){
        cout<<s[i];
    }
 }
   

}
