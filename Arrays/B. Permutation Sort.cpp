#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        int cnt=0;
        for(int i=1;i<=n;i++){

            if(a[i+1]-a[i]==1 or a[i+1]-a[i]==-1){
                cnt++;
            }
        }

        int cnt2=0;

        for(int i=1;i<=n;i++){
            if(a[i]!= i){
                cnt2++;
            }
        }

        if(cnt2==0){
            cout<<0<<endl;
        }
        else{
            cout<<cnt2-cnt<<endl;
        }



    }

}
