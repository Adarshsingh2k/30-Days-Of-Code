/*
Coin Change 
Medium Accuracy: 47.19% Submissions: 41757 Points: 4
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as input parameter and returns the number of ways to make change for N cents.


Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n).


Constraints:
1 <= n,m <= 103

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    
    //long long int util(int a[],int m, int n,int dp)
  
    long long int count( int a[], int m, int n )
    {
       
        //code here.
        
        // bottom up space efficient approach
        // what we are doing is we as to check how many ways are there
        // we are going one by one using each coin for each sum
        
        // initialize dp =0
        // dp array consist of total amount
        
        long long int dp[n+1]={0};
        
        // for paying 0 there is 1 way
        dp[0]=1;
        
        // now we start from first coin in the array
        for(int i=0;i<m;i++){
            // obviously if we start from a coin whose value is 2
            // there is no need of going to amount sum=1 because 2 rupees
            // if taken will make amoount =sum-2 or 
            //if not take then sum will remain constant and we move  to next element
            
            
            for(int j=a[i];j<=n;j++){
                
                dp[j]+=dp[j-a[i]];
            }
        }
        
        return dp[n];
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