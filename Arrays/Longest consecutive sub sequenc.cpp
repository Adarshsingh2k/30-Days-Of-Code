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

      sort(a,a+n);
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


      vector<int>v;
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

      return ans;

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
