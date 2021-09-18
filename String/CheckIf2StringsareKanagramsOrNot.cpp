/*
Check if two strings are k-anagrams or not 
Easy Accuracy: 43.75% Submissions: 17376 Points: 2
Given two strings of lowercase alphabets and a value K, your task is to complete the given function which tells if  two strings are K-anagrams of each other or not.

Two strings are called K-anagrams if both of the below conditions are true.
1. Both have same number of characters.
2. Two strings can become anagram by changing at most K characters in a string.

Example:

Input:
str1 = "fodr", str2="gork"
k = 2
Output:
1
Explanation: Can change fd to gk
Your Task:
Since this is a function problem, you don't need to take any input. Just complete the given function areKAnagrams that returns true if the strings can be turned into K-anagrams, else return false.

Constraints:
1 ≤ length of String ≤ 105
1 ≤ K ≤ length of String

Company Tags
Topic Tags
Related Courses

*/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
      /*  int n=str1.length();
        int mo=str2.length();
        
        if(n!=mo) return false;
        
        map<char,int>m;
        
        
        
        for(int i=0;i<n;i++){
            m[str1[i]]++;
            m[str2[i]]++;
        }
        
        int count=0;
        
        for(auto x:m){
            
            if(x.second==1){
                count++;
            }
            
        }
        
        if(count%2==0){
           // cout<<count;
            count=count/2;
            
            return (count<=k);
           
        }
        
        return false;*/
        
        if(str1.length()!= str2.length()) return false;
        
        int cnt=0;
        map<char, int> m;
        
        for(int i=0;i< str1.length();i++)
            m[str1[i]]++;
        
        for(int i=0;i<str2.length();i++)
        {
            if(m.find(str2[i])== m.end() || m[str2[i]]==0)
            cnt++;
            else
            m[str2[i]]--;
        }
        
        if(cnt<=k)
        return true;
        
        return false;
        
        
    
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends