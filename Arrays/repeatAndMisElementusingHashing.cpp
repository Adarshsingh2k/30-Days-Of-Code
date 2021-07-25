#include <bits/stdc++.h>
using namespace std;

/*void getMisRep(int a[],int n,unordered_map<int,bool> m){
	unordered_map<int,bool> m;

	for(auto i :a){

		// agar element map mein nahi hai toh usko
		// map mein daalo aur true krdo
		if(m.find(i)==m.end()){
			m[i]=true;
		}
		else{
			// if elemnt is already in map it tells this
			// element is repeated
			cout<<"Reapetd element->"<<" "<<i<<endl;
		}
	}

	// to find missing elemnt if elemnt is not in map
	// i.e its not initialized as true so it will go to end and return 
	// the elment that is missing

	for(int i=1;i<=n;i++){
		if(m.find(i)==m.end()){
			cout<<"Missing Element ->"<<" "<<i<<endl;
		}
	}
}
*/
int main(){
	int a[] = { 4, 3, 6, 2, 1, 1 };
    int n = 6;
     
     unordered_map<int,bool> m;

	for(auto i :a){

		// agar element map mein nahi hai toh usko
		// map mein daalo aur true krdo
		if(m.find(i)==m.end()){
			m[i]=true;
		}
		else{
			// if elemnt is already in map it tells this
			// element is repeated
			cout<<"Reapetd element->"<<" "<<i<<endl;
		}
	}

	// to find missing elemnt if elemnt is not in map
	// i.e its not initialized as true so it will go to end and return 
	// the elment that is missing

	for(int i=1;i<=n;i++){
		if(m.find(i)==m.end()){
			cout<<"Missing Element ->"<<" "<<i<<endl;
		}
	}
}