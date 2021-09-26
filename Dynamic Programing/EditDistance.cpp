/*
Edit Distance 
Medium Accuracy: 49.98% Submissions: 39521 Points: 4
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and returns the minimum number of operation required to make both strings equal. 


Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)


Constraints:
1 ≤ Length of both strings ≤ 100
Both the strings are in lowercase.

Company Tags
Topic Tags
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int dp[101][101];
    
    int edit(string s,string t,int n,int m){
        if(n==-1)return m+1;
        if(m==-1)return n+1;
        
        if(dp[n][m]!=-1) return dp[n][m];
       
       // start from last  and if both are same then save it and move forward 
        if(s[n]==t[m]) return dp[n][m]=edit(s,t,n-1,m-1);
        
        // while inserting and removing check 
        // with the perspective of one string
        
        int a=edit(s,t,n-1,m-1); // replace
        int b=edit(s,t,n-1,m); // insert
        
        int c=edit(s,t,n,m-1); //remove
        
        
        return dp[n][m]=1+min(a,min(b,c));
        
    }
    

    
    int editDistance(string s, string t) {
        // Code here
        memset(dp,-1,sizeof(dp));
        
        int n=s.length();
        int m=t.length();
        
        int dp[n][m];
        
       
        
        return edit(s,t,n-1,m-1);
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends