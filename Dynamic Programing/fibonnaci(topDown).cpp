// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int fib(long long int n,long long int dp[]){
        if(n==0 or n==1){
            return n;
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        
        long long int ans=0;
        
        ans=(nthFibonacci(n-1)+nthFibonacci(n-2))%1000000007;
        
       return dp[n]=ans;
    }
  
    long long int nthFibonacci(long long int n){
        // code here
        
        long long int dp[n+1]={0};
        
        return fib(n,dp);
        
       
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends