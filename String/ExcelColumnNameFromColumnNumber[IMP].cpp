/*
Excel Sheet | Part - 1 
Medium Accuracy: 47.89% Submissions: 11509 Points: 4
Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.

Example 1:

Input:
N = 51
Output: AY
Your Task:
Complete the function ExcelColumn() which takes N as input and returns output string.

Expected Time Complexity: O(Log(N))
Expected Auxiliary Space: O(Log(N))

Constraints:
1 ≤ N ≤ 107

Company Tags
Topic Tags
Related Courses
Related Interview Experiences

*/

// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int n)
    {
        // Your code goes here
        // logic nearly same as rverse the number or extract digit from num
        
        string out="";
        
        while(n>0){
            // yahan pe humme ptaa chalega ki last char konsa hoga
            char c='A'+((n-1)%26);
            // last char koadd krdo
            out=c+out;
            
            // yahan pe leftover kitna number bacha hai jisse column find karna hai
            n=(n-1)/26;
        }
        
        return out;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends