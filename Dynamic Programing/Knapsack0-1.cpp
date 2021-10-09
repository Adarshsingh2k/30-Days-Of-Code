/*

0 - 1 Knapsack Problem 
Medium Accuracy: 47.21% Submissions: 82670 Points: 4
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

View Bookmarked Problems
Company Tags
Topic Tags
Related Courses

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    // changing variables are n and w
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    /*int store[1001][1001]; 
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       
       memset(store,-1,sizeof(store));
       
       if(w==0 or n==0) return 0;
       
       if(store[n][w]!=-1)return store[n][w];
       
       if(wt[n-1]<=w){
         return  store[n][w]= max(val[n-1]+knapSack(w-wt[n-1],wt,val,n-1) , knapSack(w,wt,val,n-1) );
       }
       else return store[n][w]=knapSack(w,wt,val,n-1);
       
      
       
    }*/
    
     int t[1001][1001];
    
    int solve(int W, int wt[], int val[], int n){
        if(n==0 || W==0){ //base condition
            return 0;
        }
        if(t[n][W]!=-1){
            return t[n][W];
        }
        
        // if w of element is greater than capacity of bag reject it
        if(wt[n-1]>W){

            return t[n][W] = solve(W,wt,val,n-1);
        }

        // make a choice wether to choose lement or remove it
	
            return t[n][W] = max(val[n-1]+solve(W-wt[n-1],wt,val,n-1),solve(W,wt,val,n-1));
        
    }  
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(t,-1,sizeof(t));
        return solve(W,wt,val,n);
    }
    
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends