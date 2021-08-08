#include <bits/stdc++.h>
using namespace std;

int check(int n,vector<int > query){

    int si=query.size();
    /* int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    int cnt4=0; */

    vector<bool> fill(n,0);

    for(int i=0;i<si;i++){

        for(int j=1;j<=n;j++){
            if(query[i]==1){
                fill[j]=1;
            }

            else if(query[i]==2){
                if(j%2==0) fill[j]=0;
            }

            else if(query[i]==3){
                if(j%2!=0) fill[j]=0;
            }

            else{
                fill[j]=0;
            }
        }
       
        /*if(query[i]==1){
            for(int j=1;i<=n;j++){
                fill[j]=1;
            }
        }

        /* if(query[i]==2){
            for(int j=1;i<=n;j++){
                if(j%2==0) fill[j]=0;

            }
        }

        if(query[i]==3){
            for(int j=1;i<=n;j++){
                if(j%2!=0) fill[j]=0;
                
            }
        }
        if(query[i]==4){
            for(int j=1;i<=n;j++){
                 fill[j]=0;
                
            }
        }*/

        
    }

    int cnt=0;

    for(int i=1;i<=n;i++){
        if(fill[i]==1){
            cnt++;
        }

        cout<<fill[i];
    }
    cout<<endl;

    return cnt;
}

int main() {

    int n,q;

    cin>>n>>q;
    vector<int > query;
    int x;
    for(int i=0;i<q;i++){
        cin>>x;
        query.push_back(x);

    }


    cout<<check(n,query);

    
}
