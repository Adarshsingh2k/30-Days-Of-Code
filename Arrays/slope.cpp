#include <bits/stdc++.h>
using namespace std;

int slope(int x1, int y1,int x2, int y2){

	int m=(y2-y1)/(x2-x1);

	return m;

}


int main(){
	int x1,y1,x2,y2;
	int a1,b1,a2,b2;

	cin>>x1>>y1>>x2>>y2;
	cin>>a1>>b1>>a2>>b2;

	int m1=slope(x1,y1,x2,y2);
	int m2=slope(a1,b1,a2,b2);


	if(m1==m2){
		cout<<"yes";
	}
	else cout<<"no";
}