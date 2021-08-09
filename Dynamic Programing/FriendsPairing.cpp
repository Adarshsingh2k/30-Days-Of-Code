/*
Friends Pairing Problem 
Easy Accuracy: 43.16% Submissions: 36009 Points: 2
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

Example 2: 

Input: N = 2
Output: 2
Explanation:
{1} , {2} : All single.
{1,2} : 1 and 2 are paired.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countFriendsPairings() which accepts an integer n and return number of ways in which friends can remain single or can be paired up.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    long mod=1000000007;
    int countFriendsPairings(int n) 
    { 
        // code here
        
        // basic formula :==
        // for 1 persont to work alone No of ways = f(n-1)
        // for 1 person to get paired up and ways = f(n-2)*(n-1)
        /*
        So instead consider the order f(n−2)*(n−1).

This can be rewritten as f(n−2) + f(n−2) + f(n−2) + ... (n−1) times. This will be helpful afterwards

Now let's derive the recursive formula with following cases:

nth guy is single
nth guy gets paired up.
So the recursion will look something like this f(n) = f(n−1) + f(n−2)

This says if the guy is single, the question remains the same for (n−1) people or if the guy is paired up with anyone, question remain same for (n−2) people (because 2 people are now let's say gone). But heres a thing which I think is better understood with an example.

for n=4 and {A,B,C,D} as there names :

guy D chose to be single, people left : A,B,C
guy D gets paired up.
Pairing options are :

(A), (B,C)

(A,B),(C)

(A,C), (B)

So we can say:

f(n) = f(n−1)(if guy stays single) + f(n−2)(if first pair is formed) + f(n−2)(if second pair is formed) + f(n−2)(if third pair is formed).

So in essence, each pair contributes to the total, finally:

f(n) = f(n−1) + f(n−2)*(n−1)

(n−1) = no. of ways n can form a pair with n−1 people.
        
        */
        
        int dp[n + 1];
 
   dp[1]=1;
   dp[2]=2;
    for (int i = 3; i <= n; i++) {
        
         
            dp[i] = ((dp[i - 1]%mod) + ((i - 1)%mod) * (dp[i - 2]%mod))%mod;
    }
 
    return dp[n];
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
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends