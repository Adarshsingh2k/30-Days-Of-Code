#include <bits/stdc++.h>
using namespace std;

#define lli long long integer

bool hate(int n){

	while(n>0){
		if (n%11==0 or n%111==0){
			return true;
		}

		n-=111;
	}
	return false;

}

int main(){

	int t;

	cin>>t;

	while(t--){
		int n;
		cin>>n;

		if(hate(n)){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}


}
