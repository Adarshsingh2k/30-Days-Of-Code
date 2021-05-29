/*

                Palindrome String 

Easy Accuracy: 50.77% Submissions: 29247 Points: 2
Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
 

Your Task:  
You don't need to read input or print anything. Complete the function isPlaindrome() which accepts string S and returns a boolean value


Expected Time Complexity: O(Length of S) 
Expected Auxiliary Space: O(1) 


Constraints:
1 <= Length of S <= 105

Company Tags
*/

// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string s)
	{
	    // Your code goes here
	    int n=s.length();
    int i=0;
    int j=n-1;
    
    bool flag=0;
    
    while(i<=j){
        if(s[i]==s[j]){
            flag=1;
        }
        else if(s[i]!=s[j]){
            flag=0;
            break;
        }
        
        
        i++;
        j--;
    }
    
    if(flag==1){
        return 1;
    }
    else if(flag==0)
        {return 0;}
	}

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends