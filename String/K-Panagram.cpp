/*
K-Pangrams 
Easy Accuracy: 20.34% Submissions: 2182 Points: 2
Given a string str and an integer K, find whether the string can be changed into a pangram after at most k operations. A pangram is a sentence containing every letter in the english alphabet. A single operation can be used to swap an existing alphabetic character with any other alphabetic character.


Example 1:

Input:
str = "the quick brown fox jumps over the lazy dog"
k = 0
Output: 1
Explanation: the sentence contains all 26 characters 
and is already a pangram. 
Example 2:

Input:
str = "aaaaaaaaaaaaaaaaaaaaaaaaaa"
k = 25
Output: 1
Explanation: The word contains 26 instances of 'a'.
Since only 25 operations are allowed. We can keep
1 instance and change all others to make str a pangram.

Your Task:  
You dont need to read input or print anything. Complete the function kPangram() which takes str and k as input parameters and returns a boolean value which denotes if pangram is possible or not.


Expected Time Complexity: O(N) where N is length of str.
Expected Auxiliary Space: O(1)  


Constraints:
1<= N <= 104
String may contain duplicate characters.
String can contain only lowercase alphabets or space.

 

Company Tags

*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool kPangram(string str, int k);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin.ignore();
        string str;
        getline(cin,str);
        int k;
        cin>>k;
        cout<<kPangram(str,k)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool kPangram(string str, int k)
{
    // code here 
    string s="";
    for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]!=' ')
                s+=str[i];
        }
   //     cout<<s;
    if(s.length()<26)   
        return 0;
    if(s.length()>=26&&k>25)
        return 1;
    int a[26]={0};
    for(int i=0;i<s.length();i++)
        {
            a[s[i]-'a']++;
        }
    int count=0;
    for(int i=0;i<26;i++)
        {
            if(a[i]==0)
                count++;
        }
    if(count<=k&&count<s.length())
        return 1;
    else
        return 0;
        
       
	   
	    
	    
        
        
        
    
}