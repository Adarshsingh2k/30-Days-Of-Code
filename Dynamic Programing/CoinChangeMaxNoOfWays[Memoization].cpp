// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int dp[1000][1000];
    
    long long int util(int a[],int m, int n){
        
        // base conditions
        
        if(m==-1 and n>0) return 0;
        
        if(n==0) return 1;
        
        if(n<0) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        
        
        return dp[m][n]= util(a,m-1,n)+util(a,m,n-a[m]);
        
    }
  
    long long int count( int a[], int m, int n )
    {
       
        dp[m][n+1];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
                
            }
        }
        
        
        
        return util(a,m-1,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends