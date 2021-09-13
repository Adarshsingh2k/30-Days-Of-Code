/*
Rearranging arrays. Given an array of even lengths, 
find out whether the array could be rearranged in such
a way that the left half and right half of the array are the same.
Eg: arr[ ] = {5,5,7,7} then output : YES

Eg: arr[ ] = {1,2,3,4} then output : NO
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   unordered_map<int,int>m;
   for(auto x:a){
       m[a[x]]++;
   }
   int flag=0;

   for(auto x:m){
       if(x.second%2!=0){
           cout<<"False";
           flag=0;
           break;

       }
       else flag=1;
   }

   if(flag==1) cout<<"True";

}
