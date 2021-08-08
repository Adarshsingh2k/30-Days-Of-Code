/*
Length of the longest substring 
Medium Accuracy: 50.99% Submissions: 19120 Points: 4
Given a string S, find the length of the longest substring without repeating characters.


Example 1:

Input:
S = "geeksforgeeks"
Output:
7
Explanation:
Longest substring is
"eksforg".
Example 2:

Input:
S = "abdefgabef"
Output:
6
Explanation:
Longest substring are
"abdefg" , "bdefga" and "defgab".
 

Your Task:
You don't need to take input or print anything. Your task is to complete the function longestUniqueSubsttr() which takes a string S as and returns the length of the longest substring.

 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(K) where K is constant.


Constraints:
1 ≤ |S| ≤ 105
It is guaranteed that all characters of the String S will be lowercase letters from 'a' to 'z

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
       vector<int>vis(256, -1);
        
        
        
        int count=0; // total length of substring
        
        int j=0; // start index of window
        
        for(int i=0;i<s.length();i++){
            
            
            // i-> end of current window
            // now move the end forward 
            // update j with current j and the index at which same elemnt is present
            
            // every time smae char is encountered
            // j is updated with the new position that is last occurence of number +1
            
                
            j=max(j,vis[s[i]]+1);
           
           
            
                
            //now every time the char is encountered 
            // update its position in visited array
            vis[s[i]]=i;
            
            // count is the length of the window
            // count= end - start
            count=max(count,i-j+1);
            
            
        }
        
        
        
       //cout<<v.size();
        
        
        return count;
        
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends