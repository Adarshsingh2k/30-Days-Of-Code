/*

Find Missing And Repeating 
Medium Accuracy: 37.77% Submissions: 53537 Points: 4
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int rep,mis;
        // to find repetitive element
        for(int i=0;i<n;i++){
            // jab hum ith elemt  pe honge toh hum a[i] ko as a position
            //treat krenge aur wahan jaake element ko -ve krdenge
            if(arr[abs(arr[i])-1]<0) rep=abs(arr[i]);
            
            else{
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
        }
        
        
        // to find missing element
        for(int i =0;i<n;i++){
            // jo element +ve hoga uska indexed element missing hoga
            if(arr[i]>0){
                mis=i+1;
                break;
            }
        }
         
        int *ans= new int[2];
        ans[0]=rep;
        ans[1]=mis;
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends