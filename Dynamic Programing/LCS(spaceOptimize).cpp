#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        
        // for calculating  we just need 2 rows
        int dp[2][y+1];
        



        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                
                // i -> i%2 [it will change all the rows to 0 and 1]
                // i-1 -> (i+1)%2 [coz i-1%2 will give negative value and i-1%2=i+1%2 just for change of sign]

                //condition for blank
                if(i==0 or j==0){
                    dp[i%2][j]=0;
                }
                
                
                
                else if(s1[i-1]==s2[j-1]){
                    dp[i%2][j]=dp[(i+1)%2][j-1]+1;
                }
                
                else{
                    dp[i%2][j]=max(dp[(i+1)%2][j],dp[i%2][j-1]);
                }
            }
        }
        
       
        return dp[x%2][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends