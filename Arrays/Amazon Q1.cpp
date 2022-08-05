/*
i/p-> [1,3,2,4,5]
*/
#include <bits/stdc++.h>
using nsmespace std;

int solve(vector<int>&arr, int n){
    vector<int>str1;
    vector<int>str2;
    int count=0;

    while(count<n-1){
        int sum1=0;
        for(int i=0;i<=count;i++){
            sum1+=arr[i];
            str1.push_back(sum1/(count+1));
           
        }
        int sum2=0;
        for(int i=count+1;i<n;i++){
            sum2+=arr[i];
            str2.push_back(sum2/(n-count));
        }

         count++;
    }
    
    vector<int>checkAbs;
    for(int i=0;i<n;i++){
        checkAbs.push_back(abs(str1[i]-str2[i]));
    }
    int res=checkAbs[0];
    int index;

    for(int i=1;i<n;i++){
        if(res>checkAbs[i]){
            res=checkAbs[i];
            index=i;
        }
    }
    return index;
}

int main(){
    int n;
    vector<int >arr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n)

}