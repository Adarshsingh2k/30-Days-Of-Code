/*
Max and Min Products 
Easy Accuracy: 15.87% Submissions: 445 Points: 2
Given a set, we need to find the maximum and minimum possible product among all subsets of the set.


Example 1:

Input : 
arr[] = {1, 2, 3};
Output : 
Maximum product = 6
Minimum product = 1
Explanation :
Maximum product is obtained by multiplying
2, 3
Minimum product is obtained by multiplying
1
 

Example 2:

Input :
arr[] = {4, -2, 5};
Output : 
Maximum product = 20
Minimum product = -40
Explanation :
Maximum product is obtained by multiplying
4 5
Minimum product is obtained by multiplying
4, -2, 5
 

Example 3:

Input :
arr[] = {-4, -2, 3, 7, 5, 0, 1};
Output : 
Maximum product = 840
Minimum product = -420
Explanation :
Maximum product is obtained by multiplying
-4, -2, 3, 7, 5
Minimum product is obtained by multiplying
-4, 3, 7


Your Task:  
You don't need to read input or print anything. Your task is to complete the function getMaxandMinProduct() which takes the array arr[] and its size N as inputs and returns the maximum product and minimum subset product in an vector/array/list of size 2.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 20
-9 ≤ A[i] ≤ 9

*/

// C++ program to find maximum and minimum
// product from an array
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<long long int> getMaxandMinProduct(long long int arr[], long long int n)
    {
        // Your code goes here
       /* vector<long long int> out;
        long long int negMax=INT_MIN;
        long long int posMin=INT_MAX;
        
        long long int cnt0=0, cntNeg=0,prod=1,cntPos=0;
        
        for(long long int i=0;i<n;i++){
            if(arr[i]==0){
                cnt0++;
                continue;
            }
            
            if(arr[i]<0){
                cntNeg++;
                negMax=max(negMax,arr[i]);
            }
             if(arr[i]>0){
                cntPos++;
                posMin=min(posMin,arr[i]);
            }
            
            prod=prod*arr[i];
        }
        
        if(cnt0==n){
            out.push_back(0);
            out.push_back(0);
        }
        
        if(cntNeg&1){
            int minNow=prod;
            prod=prod/negMax;
            out.push_back(prod);
            out.push_back(minNow);
            
        }
        return out;*/
        
        long long minv=arr[0];
        long long maxv=arr[0];
        
        
        for(int i=1;i<n;i++)
        {
            
            long long mint=minv;
            long long maxt=maxv;
            
            
            minv=min({mint,mint*arr[i],arr[i],maxt*arr[i]});
            maxv=max({maxt,maxt*arr[i],arr[i],mint*arr[i]});
            
        }
        vector<long long> v={minv,maxv};
        return v;
        
        
        
        
    }  
};

// { Driver Code Starts.

int main()
{
    long long int t,n,a[100001],maxh,maxf;

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        vector<long long int> product = ob.getMaxandMinProduct(a, n);
        cout << product[1] << " " << product[0] << endl;
    }
}
  // } Driver Code Ends