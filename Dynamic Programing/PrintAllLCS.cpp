/*
Print all LCS sequences 
Hard Accuracy: 56.99% Submissions: 1490 Points: 8
You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.

Example 1:

Input: s = abaaa, t = baabaca
Output: aaaa abaa baaa
Example 2:

Input: s = aaa, t = a
Output: a

Your Task:
You do not need to read or print anything. Your task is to complete the function all_longest_common_subsequences() which takes string a and b as first and second parameter respectively and returns a list of strings which contains all possible longest common subsequences in lexicographical order.
 

Expected Time Complexity: O(n^4)
Expected Space Complexity: O(K * n) where K is a constant less than n.
 

Constraints:
1 <= Length of both strings <= 100

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	 int LCS(string &s,int n,string &t,int m,int i,int j,vector<vector<int>> &dp)
        {
        	if(i==n || j==m)  return 0;
        	
        	if(dp[i][j] != -1)  return dp[i][j];
        	
        	if(s[i]==t[j])  return  dp[i][j] = 1 + LCS(s,n,t,m,i+1,j+1,dp);
        	
        	return  dp[i][j] = max(LCS(s,n,t,m,i+1,j,dp) , LCS(s,n,t,m,i,j+1,dp));
        }
        void PrintAll(string &s,int n,string &t,int m,vector<vector<int>> &dp,int lcslen,string s1,int ind1,int ind2,int currlen,vector<string> &a)
        {
        	if(currlen == lcslen)
        	{
        		a.push_back(s1);
        		
        		return;
        	}
        	
        	if(ind1==n || ind2==m)  return;
        	
        	for(char c = 'a'; c <= 'z' ; c++)
        	{
        		bool flag = false;
        		
        		for(int i=ind1;i<n;i++)
        		{
        			if(s[i] == c)
        			{
        				for(int j=ind2;j<m;j++)
        				{
        					if(t[j] == c && LCS(s,n,t,m,i,j,dp) == lcslen - currlen)
        					{
        						string s2=s1;
        						s2 += c;
        						
        						PrintAll(s,n,t,m,dp,lcslen,s2,i+1,j+1,currlen+1,a);
        						
        						flag = true;
        						break;
        					}
        				}
        			}
        			
        			if(flag)
        			break;
        		}
        	}
        }
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int n = s.length();
		    int m = t.length();
		    
		    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        	
        	int lcslen = LCS(s,n,t,m,0,0,dp);
        	
        	vector<string> a;
        	
        	string s1;
        	PrintAll(s,n,t,m,dp,lcslen,s1,0,0,0,a);
        	
        	return a;
		}
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}

  // } Driver Code Ends