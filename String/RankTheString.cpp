/*
Rank The Permutations 
Medium Accuracy: 31.58% Submissions: 2106 Points: 4
Given a string, S find the rank of the string amongst all its permutations sorted lexicographically.The rank can be big. So print it modulo 1000003. 
Note: Return 0 if the characters are repeated in the string.

Example 1:

Input: S = "abc"
Output: 1
Explaination: It is the smallest 
lexicographically string of the permutation.
Example 2:

Input: S = "acb"
Output: 2
Explaination: This is the second smallest
lexicographically string of the permutation.
Your Task:
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int mod=1000003;

class Solution{
public:
    
    bool dup(string s){
        unordered_map<char,int>m;
        for(int i=0;s[i];i++){
            m[s[i]]++;
        }
        
        for(auto x:m){
            if(x.second!=1){
                return 1;
            }
        }
        
        return 0;
    }
    
    int calFactorial(int n)
    {
        if(n==0)
         return 1;
        return n*calFactorial(n-1);
        
    }
    
    int dictCount(string s,int start,int end){
        
        int count=0;
        for(int i=start+1;i<=end;i++){
            if(s[i]<s[start]) count++;
        }
        
        return count;
    }
    
    int rank(string s){
        // code here
        
        if(dup(s)) return 0;
        
        else{
            int pos=1;
            int  n = s.length();
             int k,iter=1;
        for(int i=0; i<n; i++)
        {
            k = dictCount(s,i,n-1);
            pos+= k*calFactorial(n-iter);
            iter++;
        }
        return (pos)%1000003;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.rank(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends