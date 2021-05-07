
/*
           
***********        Top k numbers in a stream 


Medium Accuracy: 45.74% Submissions: 807 Points: 4
Given N numbers in an array. Your task is to keep at-most K numbers at the top (According to their frequency).  We basically need to print top k numbers when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency.

Example 1:

Input:
N=5, K=4
arr[] = {5, 2, 1, 3, 2} 
Output: 5 2 5 1 2 5 1 2 3 5 2 1 3 5 
Explanation:
Firstly their was 5 whose frequency
is max till now. so print 5.
Then 2 , which is smaller than 5 but
their frequency is same so print 2 5.
Then 1, which is smallet among all the
number arrived, so print 1 2 5.
Then 3 , so print 1 2 3 5
Then again 2, which has the highest
frequency among all number so 2 1 3 5.
Example 2:

Input:
N=5, K=4
arr[] = {5, 2, 1, 3, 4} 
Output: 5 2 5 1 2 5 1 2 3 5 1 2 3 4 
Explanation:
Firstly their was 5 whose frequency is
max till now. so print 5.
Then 2 , which is smaller than 5 but
their frequency is same so print 2 5.
Then 1, Which is smallest among all the
number arrived, so print 1 2 5.
Then 3 , so print 1 2 3 5.
Then 4, so 1 2 3 4 as K is 4 so print
at-most k elements.
 

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function kTop() that takes array a, integer n and integer k as parameters and returns the array that contains our desired output.

 

Expected Time Complexity: O(N*K).
Expected Auxiliary Space: O(N).

 

Constraints:
1 ≤ N,K ≤ 103 

*/








// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
struct comp{
bool operator()(pair<int,int> &a,pair<int,int> &b)
{
    if(a.second==b.second)
    {
        return a.first>b.first;
    }
    return a.second<b.second;
}
};

class Solution
{
  public:
    vector<int> kTop(int a[], int n, int k) 
    { 
        //code here.
        
        vector<int >v;
    
        unordered_map<int ,int>m1;
    
    for(int i=0;i<n;i++){
        m1[a[i]]++;
        int l=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> q(m1.begin(),m1.end());
            while(!q.empty()&&l<k)
            {
                cout<<(q.top()).first<<" ";
                q.pop();
                l++;
            }
    }    
      
    return v;  
    }
    
    
};


// { Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}
  // } Driver Code Ends