#include <bits/stdc++.h>
using namespace std;

#define lli long long int

void potion(lli a[],lli n){
	lli cnt=0;
	lli sum=0;

	priority_queue<lli,vector<lli>,greater<lli>>pq;

	for(lli i=0;i<n;i++){
		sum+=a[i];

		pq.push(a[i]);
		cnt++;

		while(sum<0){
			sum-=pq.top();
			pq.pop();
			cnt--;
		}
	}


	cout<<cnt;
}

int main(){


		lli n;
		cin>>n;

		lli a[n];

		for(lli i=0;i<n;i++){
			cin>>a[i];
		}

		potion(a,n);



}
