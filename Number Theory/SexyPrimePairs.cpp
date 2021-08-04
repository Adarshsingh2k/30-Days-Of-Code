/*
Sixy Primes 
Easy Accuracy: 38.14% Submissions: 375 Points: 2
Sixy primes are prime numbers that differ from each other by six. For example, the numbers 5 and 11 are both sixy primes, because they differ by 6. Given a range of the form [L, R]. The task is to find all the sixy prime pairs in the range in increasing order.

Example 1:

Input: L = 11, R = 19
Output: [11, 17, 13, 19] 
Explanation: There are total two pair possible
with difference 6 and these are 11,17,13,19.  

Example 2:

Input: L = 6, R = 20
Output: [7, 13, 11, 17, 13, 19]
Explanation: There are total three pair possible
with difference 6 and these are 7,13,11,17,13,19. 

Your Task:  
You dont need to read input or print anything. Complete the function sixyPrime() which takes L and R as input parameter and returns all the sixy prime exist and if there are no sixy prime exist returns -1.

Expected Time Complexity: O(nloglogn)
Expected Auxiliary Space: O(n)

Constraints:
1 <= L <= R <=103
*/

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  bool check(int n){
      if(n<=1) return false;
      
      for(int i=2;i<=sqrt(n);i++){
          if(n%i==0) return false;
      }
      
      return true;
  }
    vector<int> sixyPrime(int L, int R) {
        // code here
        
        vector<int >v;
        vector<int >v2;
        
        int flag=0;
        for(int i=L;i<=R-6;i++){
            
            if(check(i) and check(i+6)){
                v.push_back(i);
                v.push_back(i+6);
                flag=1;
                
                
            }
            
            
            
        }
        
        if( flag ==1 ) return v;
        else {
            v2.push_back(-1);
            return v2;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L,R;
        cin >> L >> R;
        Solution ob;
        vector<int>ans=ob.sixyPrime(L,R);    
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends