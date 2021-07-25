#include <bits/stdc++.h>
using namespace std;

void getMisRep(int a[],int n){
	int freq[n+1]={0};

	for(int i =0;i<n;i++){
		freq[a[i]]++;
	}

	for(int i=0;i<=n;i++){
		if(freq[i]>1){
			cout<<i<<" ";
		}
		if(freq[i]==0){
			cout<<i<<" ";
		}
	}

}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	getMisRep(a,n);
}