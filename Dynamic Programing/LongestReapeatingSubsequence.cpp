/*
Longest Repeating Subsequence 
Easy Accuracy: 50.4% Submissions: 20782 Points: 2
Given a string, find the length of the longest repeating subsequence such that the two subsequences don't have same string character at the same position, i.e., any i'th character in the two subsequences shouldn't have the same index in the original string.

 

Example 1:

Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".
Example 2:

Input: str = "aab"
output: 1
Explanation: The longest reapting subsequenece
is "a".
 

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)
 

Constraints:
1 <= |str| <= 103

 

Company Tags
Topic Tags
Related Courses

*/
/**
 * prorer Explanation
 * For example: AABEBCDD
Here ABD is the longest sequence which repeated twice.
indexes : 0,2,6 & 1,4,7.

I hope you understood. And now how to approach this one. 
Let you took another string str2 same as str now you just
 need to find repeatation of alphabets except at same indexes i.e. i!=j 
(Because both strings are same so it's absolute that it'll count that one).
 * 
 * */

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    int n= str.length();
		    
		  
                vector<vector<int>> dp(n+1,vector<int>(n+1,0));

		    
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(str[i-1]==str[j-1] and i!=j){
		                dp[i][j]=1 + dp[i-1][j-1];
		            }
		            else{
		                 dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		            }
		        }
		    }
		    
		   return dp[n][n]; 
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends