/*
Implement Atoi 
Medium Accuracy: 32.9% Submissions: 73031 Points: 4
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt function.

Example 1:

Input:
str = 123
Output: 123

Example 2:

Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.
Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns 1..

Expected Time Complexity: O(|S|), |S| = length of string str.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of S<=10


Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

*/

// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        
        if(str=="\0") return 0;
        int res =0;
        int sign=1;
        int idx=0;
        
        if(str[0]=='-'){
            sign=-1;
            idx++;
        }
        
        
        for(;str[idx]!='\0';idx++){
            
            if(!isdigit(str[idx])) return -1;
            
            res = res * 10 + str[idx] - '0';
            
            
        }
        
        return sign*res;
        
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends