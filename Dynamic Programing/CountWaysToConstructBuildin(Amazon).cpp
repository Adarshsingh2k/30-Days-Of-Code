/*
Count possible ways to construct buildings 
Medium Accuracy: 31.6% Submissions: 1714 Points: 4
Given N, the number of plots on either sides of the road. Find the total ways to construct buildings in the plots such that there is a space between any 2 buildings. All plots on one side of the road are continuous.
Lets suppose ‘*’ represents a plot, then for N=3, the plots can be represented as * * * | | * * *                               

Where | | represents the road.                                                                                                                                                                  
Note: As the answer can be very large, print it mod 1000000007

 

Example 1:

Input: N = 3
Output: 25
Explanation: 3 plots, which means possible
ways for one side are BSS, BSB, SSS, SBS,
SSB where B represents a building and S
represents an empty space Total possible 
ways are 25, because a way to place on one
side can correspond to any of 5 ways on other
side.
Example 2:

Input: N = 10
Output: 20736
Explanation: There are 20736 ways for N = 10.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function ToralWays() which takes N as input parameter and returns the total possible ways modulo 109 + 7.
 

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
 

Constraints:
1 <= N <= 100000

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	    // Code here
	    
	    long long int dpP[n+1],dpS[n+1];
	    dpP[1]=1;
	    dpS[1]=1;
	    
	    for(long long int i=2;i<=n;i++){
	        dpP[i]=dpS[i-1]%1000000007;
	        dpS[i]=(dpS[i-1]%1000000007)+(dpP[i-1]%1000000007);
	    }
	    
	    long long int out=((dpP[n]%1000000007)+(dpS[n]%1000000007))%1000000007;
	    
	    return (((out%1000000007)*(out%1000000007))%1000000007);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends