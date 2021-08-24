/*
91. Decode Ways
Medium

5223

3574

Add to List

Share
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with 0.
The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of which start with 0.
Hence, there are no valid ways to decode this since all digits need to be mapped.
Example 4:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).

*/


// Link To question ->https://leetcode.com/problems/decode-ways/
// link to gfg Qustion->https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1#


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		    // Code here
		    
		    int n=s.length();
		    int dp[n];
		    if (s[0] == '0') return 0;
             
            // agar size 1 hai toh bss ek hi way hogi
            if (n == 1) return 1;
            
            dp[0]=1;
             dp[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');
            
            for(int i=2;i<n;i++){
                // edge case: we quit for 2 consecutive zeros
                if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0')) return 0;
                
                // base case: we always keep the previous set of combinations,
                //unless we met a 0
                dp[i] = s[i] != '0' ? dp[i - 1] : 0;
                // we go and look 2 positions behind if we can make a digit in the 10-26 range
                if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') dp[i] =(dp[i]+ dp[i - 2])%1000000007;
            }
            
            return dp[n - 1]%1000000007;
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends