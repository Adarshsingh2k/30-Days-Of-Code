/*
                  Zero Sum Subarrays 
                  
Medium Accuracy: 50.41% Submissions: 14312 Points: 4
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array arr and its size n as input parameters and returns the total number of sub-arrays with 0 sum. 
 

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
 

Constraints:    
1<= n <= 107
-1010 <= arri <= 1010

 

Company Tags
Topic Tags
 Arrays Hash

*/

// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> a, int n ) {
        //code here
        
     unordered_map<int,int>cnt;
     int psum=0;
     
     int c=0;
     
     for(int i=0;i<n;i++){
         psum+=a[i];
         
         if(psum==0)c++;
         
         if(cnt.find(psum)!=cnt.end()){
             c+=cnt[psum];
         }
         
         cnt[psum]++;
     }
     
     
     
     return c;
     
     
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
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends