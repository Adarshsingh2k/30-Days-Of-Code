/*
Medium Accuracy: 34.32% Submissions: 6975 Points: 4
Given two binary strings A and B consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.


Example 1:

Input:
A = "1101", B = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Example 2:

Input: 
A = "10", B = "01"
Output: 11
Explanation: 
  10
+ 01
  11

Your Task:
You don't need to read input or print anything. Your task is to complete the function addBinary() which takes 2 binary string A and B and returns a binary string denoting the addition of both the strings.


Expected Time Complexity: O(max(|A|, |B|)).
Expected Auxiliary Space: O(max(|A|, |B|)) (for output string).


Constraints:
1 ≤ |A|, |B| ≤ 106

Company Tags
Topic Tags
Related Courses
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    
	    string out;
	    
	    int carry=0;
	    
	    int i=a.size()-1;
	    int j=b.size()-1;
	    
	    while(i>=0 or j>=0 ){
	        int sum=carry;
	        
	        if(i>=0){
	            sum+=a[i--]-'0';
	        }
	        //else sum+=0;
	        
	        if(j>=0){
	            sum+=b[j--]-'0';
	            
	        }
	        //else sum+=0;
	        
	        carry= (sum>1)?1:0;
	        
	        out+=to_string(sum%2);
	        
	        
	       
	    }
	    
	    if(carry) out+=to_string(carry);
	    reverse(out.begin(),out.end());
	    
	   /* if(out[0]=='0'){
	        return substr(out.begin()+1,out.end());
	    }
	    
	    return out;*/
	    
	    i=0;
	    while(out[i]=='0'){
	        i++;
	    }
	    return out.substr(i);
	    
	  
	    
	}
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends