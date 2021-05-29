/*
                        Multiply two strings

Medium Accuracy: 26.16% Submissions: 63789 Points: 4
Given two numbers as stings s1 and s2. Calculate their Product.


Example 1:

Input:
s1 = "33"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253

Your Task:

You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.


Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2) ; where n1 and n2 are sizes of strings s1 and s2 respectively.

 

Constraints:
1 <= length of s1 and s2 <= 103

Company Tags

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
    
   if(s1=="0"||s2=="0")
   return "0";
   
   int n=s1.length();
   int m=s2.length();
   
   string sign="";
   
   if(s1[0]=='-'&&s2[0]=='-')
   sign="";
   
   else if(s1[0]=='-'||s2[0]=='-')
   sign="-";
   
   if(s1[0]=='-')
   {
       s1=s1.substr(1);
       n--;
   }
   
   if(s2[0]=='-')
   {
       s2=s2.substr(1);
       m--;
   }
   
   //cout<<s1<<"\n"<<s2<<"\n";
   
   vector<int> res(m+n,0);
   
   for(int i=n-1;i>=0;i--)
   {
       for(int j=m-1;j>=0;j--)
       {
           int mul=(s1[i]-'0')*(s2[j]-'0');
           
           int sum=res[i+j+1]+mul;
           
           res[i+j+1]=sum%10; //storing sum at i+j+1 index  jo ki basically ki last index hai
                             //jo baad mein  decrement hoga jaise loop age badhega aur next
                             //idx mein store hogA
           
           res[i+j]+=sum/10; //carry propagation ; carry har bar last second idx mein update hoga
           
       }
   }
   
   int i=0;
   while(i<m+n&&res[i]==0)
   i++;
   
   string ans=sign;
   // yahan par jo i aayega wo upar se increment ho kar aayega jahan pe
   // 0 starting mein nahi hai
   while(i<m+n)
   {
       ans+=to_string(res[i]);
       i++;
   }
  
  return ans;
       
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends