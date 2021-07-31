/*
Minimum Difference in an Array 
Easy Accuracy: 88.87% Submissions: 2000 Points: 2
Given a array of size n, find the minimum difference between any pair of elements in given array.


Example 1:

Input: 
Arr = [2, 4, 5, 9, 7]
Output: 
1
Explanation: Difference between 5 and 4 is 1.

Example 2:

Input: 
Arr = [3, 10, 8, 6]
Output: 
2
Explanation: Difference between 8 and 6 is 2.


Your Task:  
You don't need to read or print anything. Your task is to complete the function MinimumDifference() which takes the array and its size as input parameters and returns the minimum difference  between any pair in given array.
 


Expected Time Compelxity: O(n* log(n))
Expected Space Complexity: O(1)

 

Constraints:
1 <= n <= 105
1 <= Arr[i] <= 109

*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to find minimum difference between any pair of elements in an array.
    int MinimumDifference(int arr[], int n)
    {
        //code here
        sort(arr,arr+n);
        int min_so_far=arr[0];
        int min_sum=INT_MAX;
        
        for(int i=1;i<n;i++){
            min_so_far=arr[i]-arr[i-1];
           // cout<<min_so_far<<endl;
            if(min_so_far<min_sum){
            min_sum=min_so_far;
        }
        }
        
        
        
        return min_sum;
    }
};

// { Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n]; 
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int diff = ob.MinimumDifference(arr, n);
	    cout << diff << endl;
	}
	return 0;
}  // } Driver Code Ends