/*

Maximum Rectangular Area in a Histogram
Medium Accuracy: 47.42% Submissions: 18247 Points: 4
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation:


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram
will be 8  and there will be 2 consecutive
histogram. And hence the area of the
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 106
1 <= arr[i] <= 1012

Company Tags

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long a[], int n)
    {
        // Your code here

       /*stack<long long>s;
        int h;
        int i=0;
        /**vector<long long>v;

        for(int i=0;i<n;i++){
            v.push_back(a[i]);
        }
        //v.push_back(0);

        long long area=0;

        long long toparea;

        while(i<n){
           if(s.empty() or a[s.top()]<=a[i]){
               s.push(i++);
           }

           else{

               h=a[s.top()];
               s.pop();

               if(s.empty()){
                   toparea=h*i;
               }
               else{
                   toparea=h*(i-s.top()-1);
               }

               area=max(area,toparea);
           }
        }

        while(s.empty()==false){
             h=a[s.top()];

             s.pop();

              if(s.empty()){
                   toparea=h*i;
               }
               else{
                   toparea=h*(i-s.top()-1);
               }

               area=max(area,toparea);


        }


        return area;*/
        long long maxi = 0;
        long long area = 0;
        long long tp ;

       stack <long long> st;

       int i = 0;
       while(i<n)
       {
           if(st.empty()||a[st.top()]<=a[i])
           {
               st.push(i);
               i++;
           }
           else
           {
               tp = st.top();
               st.pop();

               area = a[tp]*(st.empty() ? i : i-st.top()-1);

               if(area>maxi)maxi = area;
           }
       }

       while(st.empty()==false)
       {
           tp = st.top();
           st.pop();

           area = a[tp]*(st.empty() ? i : i-st.top()-1);

           if(area>maxi)maxi = area;
       }
       return maxi;


    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;

    }
	return 0;
}
  // } Driver Code Ends
