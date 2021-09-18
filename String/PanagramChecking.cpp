/*
Pangram Checking 
Easy Accuracy: 51.81% Submissions: 15494 Points: 2
Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet.

Example 1:

Input:
S = Bawds jog, flick quartz, vex nymph
Output: 1
Explantion: In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.
Example 2:

Input:
S = sdfs
Output: 0
Explantion: In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.
Your Task:
 You need to complete the function checkPangram() that takes a string as a parameter and returns true if the string is a pangram, else it returns false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 ≤ |S| ≤ 104

Topic Tags

*/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        
        vector<bool> check(26, false);
         int index;
        
        for(int i=0;i<str.size();i++){
            int c=str[i];
            if(isupper(c)){
                
                str[i]=tolower(c);
            }
        }
        
        for(int i=0;i<str.size();i++){
            if(islower(str[i])){
               index = str[i] - 'a';
            }
            else continue;
            
             check[index] = true;
        }
        
         for (int i = 0; i <= 25; i++)
        {    if (check[i] == false)
                return (false);
        }
     
    // If all characters were present
        return (true);
       
        
    }

};

// { Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
  // } Driver Code Ends