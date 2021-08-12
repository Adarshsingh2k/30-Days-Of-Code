/*
Maximum Sub-String after at most K changes 
Medium Accuracy: 47.01% Submissions: 349 Points: 4
We have a string s of length n, which consist only UPPERCASE characters and we have a number k (always less than n and greater than 0). We can make at most k changes in our string such that we can get a sub-string of maximum length which have all same characters.
 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Change 2 'B' into 'A'.
Example:

Input: s = "ABCD", k = 1
Output: 2
Explanation: Change one 'B' into 'A'.
 

Your Task:
You don't need to read print anything. Your task is to complete the function characterReplacement() which takes s and k as input parameter and returns the maximum length of sub-string after doing k changes.
 

Expected Time Complexity: O(n)
Expected Space Complexity: O(26)
 

Constraints:
1 <= n <= 104

*/

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    
    
    
	public:
	
	
	    int helper(string& A, int n, int k, char ch){
	        int maxlen = 1;
            int cnt = 0;
            int l = 0, r = 0;
            
            // Start traversing the string
            while (r < n) {
     
                /* if character is not same as ch
                   increase count */
                if (A[r] != ch)
                    ++cnt;
 
                // if count > k tab cnt ko kam krrdo kyunki K se jyada
                //changes nahi krr sakte hain
                while (cnt > k) {
                    if (A[l] != ch)
                        --cnt;
                    ++l;
                }
 
                // max lenght wil bee from [right-left+1]
                maxlen = max(maxlen, r - l + 1);
                ++r;
            }
            return maxlen;
	    }
	    
		int characterReplacement(string A, int k){
		    // Code here
		   /* map<char,int>m;
		    
		    int n=s.length();
		    
		    for(int i=0;i<n;i++){
		        m[s[i]]++;
		    }
		    int cMax=-1;
		    
		    for(auto x:m){
		        
		        if(x.second>cMax){
		            cMax=x.second;
		        }
		        
		    }
		    
		    if(cMax==n) return n;
		    
		    else if(cMax<n) {
		        if(cMax+k<=n){
		            return cMax+k;
		        }
		        else return n;
		    }*/
		    int n=A.length();
		    int maxl = 1;
            for (int i = 0; i < 26; ++i) {
                maxl = max(maxl, helper(A, n, k, i+'A'));
                maxl = max(maxl, helper(A, n, k, i+'a'));
            }
            return maxl;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends