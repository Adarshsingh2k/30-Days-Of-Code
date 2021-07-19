/*

Allocate minimum number of pages 
Hard Accuracy: 48.87% Submissions: 21020 Points: 8
You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:
113
Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.
Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:
32
Explanation:
Allocation is done as 
{15,17} and {20}

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 105
1 <= A [ i ] <= 106
1 <= M <= 105

Company Tags
*/


// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool allocate(int arr[],int n,int mid, int m){
        
        
        int sumPg=0;  // sum of Pages in eacg book
        int stu=1;    // No of students
        
        for(int i=0;i<n;i++){
            
            // Aggar koi element arr ka mid se bada hoga toh 
            // hum mid ko increase krna hoga toh yahan se false return 
            // krenge toh woh main function mein jaake mid+1 ho jaega
            
            if(arr[i]>mid) return false;
            
            // if sumPg+ arr[i] more than mid then we will send that arr elemnt
            // to next student
            if(sumPg+arr[i]>mid){
                stu++;
                // sumPg will get updadted with the array element
                sumPg=arr[i];
                
                // if number of student more tha given no of students return false
                if(stu>m)return false;
            }
            
            // keep summing no of pages in each book
            else sumPg+=arr[i];
        }
        
        return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        
       
        int low=0;
        int ans=0;
        int sumArr=0;
        
        for(int i=0;i<n;i++) sumArr+=arr[i];
        int up=sumArr;
        
        while(low<=up){
            int mid=(low+up)/2;
            
            // iff allocate returns true
            if(allocate(arr,n,mid,m)){
                ans=mid; // ans will store the new value of mid;
                up=mid-1;
            }
            // if alloctae returns false
            else low=mid+1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends