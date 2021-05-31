#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		int a[n];

		for(int i=0; i<n;i++){
			cin>>a[i];
		}


		for(int i=0;i<n;i++){

                while(m>0){
                    if(a[i+1]==1 and a[i-1]==0 ){
                        a[i]=1;

                    }
                    else if(a[i+1]==0 and a[i-1]==1){
                        a[i]=1;
                    }

                    m--;
                }



		}

		for(int i=0; i<n;i++){
			cout<<a[i];
		}



	}


}
