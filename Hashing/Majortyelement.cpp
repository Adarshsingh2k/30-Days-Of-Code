/*
Majority Element 
Easy Accuracy: 48.6% Submissions: 67369 Points: 2
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.

Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
 

Constraints:
1 <= N <= 107
0 <= Ai <= 106

Company Tags
 Accolite Amazon D-E-Shaw Microsoft Nagarro Google
Topic Tags
 Arrays Searching Greedy
Related Courses
Related Interview Experiences
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int m=INT_MIN;
        unordered_map<int,int>mp;
       // int cnt=0;
        for(int i=0;i<size;i++){
            
                mp[a[i]]++;
            
            
        }
            int cnt=0;
            for(auto i:mp){
                if(i.second>size/2){
                    cnt=1;
                    
                    return i.first;
                }
            }
            
            if(cnt==0){
                return -1;
            }
        
    }
   
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends