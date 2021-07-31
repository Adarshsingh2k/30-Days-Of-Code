/*
Minimum steps to make product equal to one 
Easy Accuracy: 38.84% Submissions: 4761 Points: 2
Given an array arr[] containing N integers. In one step, any element of the array can either be increased or decreased by one. Find minimum steps required such that the product of the array elements becomes 1.

 

Example 1:

Input:
N = 3
arr[] = {-2, 4, 0}
Output:
5
Explanation:
We can change -2 to -1, 0 to -1 and 4 to 1.
So, a total of 5 steps are required
to update the elements such that
the product of the final array is 1. 
Example 2:
Input:
N = 3
arr[] = {-1, 1, -1} 
Output :
0
Explanation:
Product of the array is already 1.
So, we don't need to change anything.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function makeProductOne() which takes an integer N and an array arr of size N as input and returns the minimum steps required.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
-103 ≤ arr[i] ≤ 103

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        // code here
        int cnteven = 0;
        int cntz = 0;
        int sum = 0;
        for(int i = 0 ; i< N ; i ++)
        {
            if(arr[i] == -1)
            {
                cnteven ++;
            }
            if(arr[i] < -1)
            {
                cnteven ++;
                sum += abs(arr[i] + 1);
            }
            if(arr[i] > 1)
            {
                sum += (arr[i] - 1);
            }
            if(arr[i] == 0)
            {
                cntz++;
            }
        }
        sum += cntz;
        if(cnteven % 2 != 0)
        {
            if(cntz == 0)
            {
                sum += 2;
            }
        }
        
        return sum;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.makeProductOne(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends