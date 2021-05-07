/*

Kth largest element in a stream 
Medium Accuracy: 42.29% Submissions: 2427 Points: 4
Given an input stream arr[] of n integers, find the kth largest element for each element in the stream.

Example 1:

Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:
-1 -1 -1 1 2 3
Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.
Example 2:

Input:
k = 1, n = 2
arr[] = {3, 4}
Output:
3 4 
Explanation: 
For the 1st and 2nd element the 1st largest 
element is itself.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes 2 Integers k, and n and also an array arr[] of size n as input and returns the kth largest element in the stream.

 

Expected Time Complexity: O(nlogk)
Expected Auxiliary Space: O(n)

 

Constraints:
1 ≤ k ≤ n ≤ 105
1 ≤ arr[i] ≤ 105

*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
      vector<int> ans(n);
 
    // Creating a min-heap using priority queue
    priority_queue<int, vector<int>, greater<int> > pq;
 
    // Iterating through each element
    for (int i = 0; i < n; i++) {
        // If size of priority
        // queue is less than k
        if (pq.size() < k){
            pq.push(arr[i]);
            
        }
      else 
            if (arr[i] > pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            
        }
 
        // If size is less than k
        if (pq.size() < k)
            ans[i] = -1;
        else
            ans[i] = pq.top();
    }
 
    return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends