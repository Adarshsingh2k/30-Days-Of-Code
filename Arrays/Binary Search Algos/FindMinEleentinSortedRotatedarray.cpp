/*

Minimum element in a sorted and rotated array 
Easy Accuracy: 53.26% Submissions: 10143 Points: 2
A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Example

Input
N = 5
arr[] = {4 ,5 ,1 ,2 ,3}
Output
1
Explanation: 1 is the minimum element in
the array.
Example

Input
N = 6
arr[] = {10, 20, 30, 40, 50, 5, 7}
Output
5
Explanation:
Here 5 is the minimum element.
 

Your Task:
Complete the function findMin() which takes an array arr[] and n, size of the array as input parameters, and returns the minimum element of the array.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(log N).

Constraints:
1 ≤ N ≤ 100000
1 ≤ A[i] ≤ 1000000

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int low=0;
        int high=n-1;
        
        
        // base case when array is already sorted
        if(arr[low]<=arr[high]) return arr[0];
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]>arr[mid+1]) return arr[mid+1];
            else if(arr[mid]<arr[mid-1]) return arr[mid];
            // if first half is sorted
            else if(arr[low]<=arr[mid] ) low=mid+1;
            
            // if second half is sorted
            else if(arr[mid]<=arr[high]) high=mid-1;
            
        }
        
        
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
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends