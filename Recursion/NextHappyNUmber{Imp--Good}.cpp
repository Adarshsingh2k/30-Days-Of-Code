/*
Next Happy Number 
Hard Accuracy: 50.1% Submissions: 1214 Points: 8
For a given non-negative integer N, find the next smallest Happy Number. A number is called happy if it leads to 1 after a sequence of steps wherein each step number is replaced by the sum of squares of its digit that is if we start with Happy Number and keep replacing it with digits square sum, we reach 1.
 

Example 1:

Input:
N = 8
Output:
10
Explanation:
Next happy number
after 8 is 10 because
1*1 + 0*0 = 1
Example 2:

Input:
N = 10
Output
13
Explanation:
after 10, 13 is a happy
number because
1*1 + 3*3 = 10
1*1 + 0*0 = 1

Your Task:
You don't need to read input or print anything. Your task is to complete the function nextHappy() which takes an integer N as input parameters and returns an integer, next Happy number after N.


Expected Time Complexity: O(Nlog10N)
Expected Space Complexity: O(1)
 

Constraints:
1<=N<=103

Topic Tags

*/

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    
     bool solve(int x){
        if(x<=10){
            if(x==1 || x==7 || x==10) return true;
            return false;
        }
        int sum = 0;
        while(x>0){
            int rem = x%10;
            sum += (rem * rem);
            x /= 10;
        }
        return solve(sum);
    }
    
    int nextHappy(int N){
        // code here
       for(int i=N+1;;i++){
           if(solve(i)) return i;
           
       }
        
        return -1;
        
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends