/*
    Longest consecutive subsequence
Medium Accuracy: 48.9% Submissions: 39554 Points: 4
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.


Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105

Company Tags
 Amazon Walmart Microsoft
Topic Tags
 Hash
Related Courses

*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      //Your code here

      //sort(a,a+n);
     /* int dif=0;
      vector<int >v;

      for(int i=0;i<n;i++){
          dif=a[i]-dif;

          if(dif==1){
              v.push_back(a[i]);
          }


      }

      int s=v.size();

      return s;*/


      /*vector<int>v;
      int ans=0;
      int count=0;

      v.push_back(a[0]);

      for(int i=1;i<n;i++){

          if(a[i]!=a[i+1]){
              v.push_back(a[i]);
          }

      }

      for(int i=0;i<v.size();i++){
          if(i>0 and v[i]==v[i-1]+1){
              count++;
          }
          else{
              count=1;
          }

          ans= max(ans,count);
      }

      return ans;*/


      set<int> s;

      for(int i=0;i<n;i++){
          s.insert(a[i]);
      }

      int totalsize=0;

      for(int i=0;i<n;i++){

          //we are finding element less then a[i]
          if(s.find(a[i]-1)==s.end()){
              //if there is no samll element store a[i]
              int j= a[i];

              int cnt=0;
              //now check for element greater than a[i]
              //and maintain there count
              while(s.find(j)!=s.end()){
                  j++;
                  cnt++;

                  totalsize=max(totalsize,cnt);



              }
          }
      }






      return totalsize;






    }
};

// { Driver Code Starts.

// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }

    return 0;
}  // } Driver Code Ends
