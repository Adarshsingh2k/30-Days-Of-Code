/*
Ugly Numbers 
Hard Accuracy: 50.0% Submissions: 13248 Points: 8
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.

Example 1:

Input:
N = 10
Output: 12
Explanation: 10th ugly number is 12.
Example 2:

Input:
N = 4
Output: 4
Explanation: 4th ugly number is 4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function getNthUglyNo() which takes an integer n as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 104

 

Company Tags

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    
	    vector<ull> dp(n+1);
	    dp[1]=1;
	    
	    ull m2(1),m3(1),m5(1);
	    
	    for(ull i=2;i<=n;i++){
	       ull f2=2*dp[m2]; 
	       ull f3=3*dp[m3]; 
	       ull f5=5*dp[m5]; 
	       
	       ull minF= min(f2,min(f3,f5));
	       dp[i]=minF;
	       if(minF==f2) m2++;
	       if (minF==f3) m3++;
	       if(minF==f5) m5++;
	    }
	    
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends