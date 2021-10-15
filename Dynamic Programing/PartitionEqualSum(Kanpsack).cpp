/*
Partition Equal Subset Sum 
Medium Accuracy: 38.0% Submissions: 73938 Points: 4
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool subSum(int arr[],int sum, int n){
        int store[n+1][sum+1];
        
        // initialze the arry for base cond
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0 and j==0) store[i][j]=0;
                else if(i==0) store[i][j]=0;
                else if(j==0) store[i][j]=1;
                
                
            }
        }
        
        // foloow thw logic of knapsack
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                if(arr[i-1]>sum){
                    store[i][j]=store[i-1][j];
                }
                
                // check from where we get true  either by including or excludin 
                // current element of array
                store[i][j]=store[i-1][j-arr[i-1]] or store[i-1][j];
                
            }
        }
        
        return store[n][sum];
        
    }

    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
       // if summ will be even then inly
        // equal partititon is possible
        
        if(sum%2!=0) return 0;
        
        // if sum is even question reduces to subset sum
        return subSum(arr,sum/2,n);
        
         
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends