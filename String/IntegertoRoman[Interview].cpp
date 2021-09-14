/*
Convert to Roman No 
Basic Accuracy: 49.9% Submissions: 18378 Points: 1
Given an integer n, your task is to complete the function convertToRoman which prints the corresponding roman number of n. Various symbols and their values are given below.

I 1
V 5
X 10
L 50
C 100
D 500
M 1000

 

Example 1:

Input:
n = 5
Output: V
 

Example 2:

Input:
n = 3
Output: III
 

Your Task:
Complete the function convertToRoman() which takes an integer N as input parameter and returns the equivalent roman. 

 

Expected Time Complexity: O(log10N)
Expected Auxiliary Space: O(log10N * 10)

 

Constraints:
1<=n<=3999

Company Tags
Topic Tags
Related Courses
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string convertToRoman(int n) {
        // code here
        int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string roman[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;
        
        string res;
        
        while(n>0){
            // kep dividing number to get most significant bit
            int quo=n/num[i];
            n=n%num[i];
            while(quo--){
                cout<<roman[i];
                
            }
            i--;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}  // } Driver Code Ends