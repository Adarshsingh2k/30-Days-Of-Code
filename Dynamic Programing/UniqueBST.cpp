/*
Unique BST's 
Medium Accuracy: 44.17% Submissions: 29016 Points: 4
Given an integer. Find how many structurally unique binary search trees are there that stores the values from 1 to that integer (inclusive). 

Example 1:

Input:
N = 2
Output: 2
Explanation:for N = 2, there are 2 unique
BSTs
     1               2  
      \            /
       2         1
Example 2:

Input:
N = 3
Output: 5
Explanation: for N = 3, there are 5
possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function numTrees() which takes the integer N as input and returns the total number of Binary Search Trees possible with keys [1.....N] inclusive. Since the answer can be very large, return the answer modulo 1000000007.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N).

Constraints:
1<=N<=1000

Company Tags
Topic Tags
Related Courses
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        // Your code here
       /*
       memoization
       
       int dp[n+1];
       for(int i=0;i<=n;i++){
           dp[i]=-1;
       }
         if(n==0 or n==1) return dp[n]=1;;
         
        if(dp[n]!=-1) return dp[n];
       
        
        int click=0;
        
        for(int i=1;i<=n;i++){
            click+=numTrees(i-1)*numTrees(n-i);
            
        }
        return dp[n]=click;
        */
        
        long long int dp[N + 1] = {0};
        long long mod=1000000007;
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += ((dp[i-j] % mod) * (dp[j-1] % mod)) % mod;
             }
        }
        return dp[N] % mod;
       
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends