/*
Largest prime factor 
Medium Accuracy: 46.44% Submissions: 5895 Points: 4
Given a number N, the task is to find the largest prime factor of that number.
 

Example 1:

Input:
N = 5
Output:
5
Explanation:
5 has 1 prime factor 
i.e 5 only.
Example 2:

Input:
N = 24
Output:
3
Explanation:
24 has 2 prime factors 
3 and 2 in which 3 is 
greater

Your Task:
You don't need to read input or print anything. Your task is to complete the function largestPrimeFactor() which takes an integer N as input parameters and returns an integer, largest prime factor of N.
 

Expected Time Complexity: O(sqrt(N))
Expected Space Complexity: O(1)
 

Constraints:
1 <= N <= 105

*/

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        // code here
        
        priority_queue<long long int>pq;
         int maxc=1;
        
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                //pq.push(i);
                maxc=i;
                n/=i;
            }
            
            
        }
        
        if(n>=2){
            maxc=n;
        }
        
        //long long int maxx=pq.top();
        
        // if we remove priority queue it will be space O(1)
        
        return maxc;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends