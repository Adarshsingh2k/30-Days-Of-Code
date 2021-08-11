/*
Bleak Numbers 
Medium Accuracy: 51.17% Submissions: 1845 Points: 4
Given an integer, check whether it is Bleak or not.

A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Example 1:

Input: 4
Output: 1
Explanation: There is no any possible x
such that x + countSetbit(x) = 4
Example 2:

Input: 3
Output: 0
Explanation: 3 is not a Bleak number as 
2 + countSetBit(2) = 3.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function is_bleak() which takes n as input parameter and returns 1 if n is not a Bleak number otherwise returns 0.
 

Expected Time Complexity: O(log(n) * log(n))
Expected Space Complexity: O(1)
 

*/

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:

    int countB(int n){
        
        int count=0;
        while(n){
            n&=(n-1);
            count++;
        }
        
        return count;
    }
    
	int is_bleak(int n)
	{
	    // Code here.
	    int x=ceil(log2(n));
	    // basically  ceil of log2 eill only check
	    // elemrnts from N-ceil(log2(n))
	    // decrease the complexity from N to logN
	    for(int i=n-x;i<n;i++){
	        if(i+countB(i)==n) return false;
	        //break;
	    }
	    
	    return true;
	}
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}
  // } Driver Code Ends