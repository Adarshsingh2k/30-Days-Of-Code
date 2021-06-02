/*
    Longest Common Prefix in an Array 
Easy Accuracy: 49.03% Submissions: 7165 Points: 2
Given a array of N strings, find the longest common prefix among all strings present in the array.

Example 1:

Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common
prefix in all the given strings.
â€‹Example 2:

Input: 
N = 2
arr[] = {hello, world}
Output: -1
Explanation: There's no common prefix
in the given strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonPrefix() which takes the string array arr[] and its size N as inputs and returns the longest common prefix common in all the strings in the array. If there's no prefix common in all the strings, return "-1".


Expected Time Complexity: O(N*max(|arri|)).
Expected Auxiliary Space: O(max(|arri|)) for result.


Constraints:
1<=N<=103
1<=|arri|<=103

*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:

    string prfxutil(string s1, string s2){
        string res;
        for( int i=0,j=0; i<s1.length(),j<s2.length();i++,j++){
            if(s1[i]==s2[j]){
                res.push_back(s1[i]);
            }
            else{
                break;
            }
            
        }
        
        return res;
    }
    
    
    string longestCommonPrefix (string str[], int n)
    {
        // your code here
        
       string prfx=str[0];
       for( int i=1;i<n;i++){
           prfx=prfxutil(prfx,str[i]);
       }
       
       if(prfx.size()==0){
           return "-1";
       }
       
       return prfx;
 
    }   
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends