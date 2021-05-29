#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){

		int n;
		cin>>n;
		int s=2*n;
		int a[s];
		for(int i=0;i<s;i++ ){
			cin>>a[i];
		}

		sort(a,a+s);

		//use 2 pointer approach

		int start=0;
		int end=s-1;

		while(start<=end){
			if(start==end){
				cout<<a[start]<<" ";
			}

			else {
				cout<<a[start]<<" "<<a[end]<<" ";
			}

			start++;
			end--;
		}


		cout<<endl;

	}

}
