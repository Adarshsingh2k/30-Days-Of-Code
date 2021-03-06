/*
                    Kadane's Algorithm

Medium Accuracy: 51.0% Submissions: 70858 Points: 4
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.



Example 1:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which
is a contiguous subarray.
Example 2:

Input:
N = 4
arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1
of element (-1)


Your Task:
You don't need to read input or print anything. The task is to complete the function maxSubarraySum() which takes arr and N as input parameters and returns the sum of subarray with maximum sum.



Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)



Constraints:
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int a[], int n){

        // Your code here
        int cursum=0;
        int maxsum=INT_MIN;

        for(int i=0;i<n;i++){
            cursum+=a[i];

            if(cursum<0){
                cursum=0;
            }
            if(maxsum<cursum){
                maxsum=cursum;
            }
        }

        return maxsum;
    }
};
// { Driver Code Starts.

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
