/*

Minimize the Heights II 
Medium Accuracy: 28.62% Submissions: 100k+ Points: 4
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between 
the largest and the smallest is 17-6 = 11. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function getMinDiff() which takes the arr[], n and k as input parameters and returns an integer denoting the minimum difference.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)

Constraints
1 ≤ K ≤ 104
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 105

Company Tags
 Adobe Microsoft


*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int a[], int n, int k) {
        // code here
        
        sort(a,a+n);
        /*int dif=a[n-1]-a[0];
        
        int str=a[n-1];
        
        int half=str/2;
        
        for(int i=0;i<n;i++){
            if(a[i]<=half){
                a[i]+=k;
            }
            else{
                a[i]-=k;
            }
        }
        
        sort(a,a+n);
        int diff=abs(a[0]-a[n-1]);
        
        return min(diff,dif);*/
        
        int mx,mi;
        
        int ans=a[n-1]-a[0];
        
        for(int i=1;i<n;i++){
            if(a[i]>=k)//non zero 
            {
                mx=max(a[i-1]+k,a[n-1]-k);//max element last elemt aur
                                         // start se compare krenfge kyunki last element 
                                        //toh bada hi rahega
                mi=min(a[0]+k,a[i]-k); //min elemnt first aur uske baad se compare krenge kyunki
                                        // first element toh min hi rahega aur coi condition aisi hui
                                        //JISME MIN ADDITON KE BAAD BHI DUSRE ELEMENT SE CHOTA HAI
                 ans=min(ans,mx-mi);
            }
            
           
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends