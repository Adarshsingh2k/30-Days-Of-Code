/*
Count of subsets with sum equal to X
Difficulty Level : Medium
Last Updated : 23 Aug, 2021
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.

Examples: 
Input: arr[] = {1, 2, 3, 3}, X = 6 
Output: 3 
All the possible subsets are {1, 2, 3}, 
{1, 2, 3} and {3, 3}

*/

#include <bits/stdc++.h>
using namespace std;

int countSum(int a[],int n,int k){
    int dp[n+1][k+1];

    dp[0][0] = 1;
    // initialize according to conditions for empty array and 0 sum
    for (int i = 1; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) dp[i][0] = 1;

// concept of Knapsack
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if (a[i-1] > j) {
                dp[i][j] = dp[i - 1][j];
            } 
           //we have to count all possible ways
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i-1]];
           
        }
    }


    return dp[n][k];

}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;

    cout<< (countSum(a,n,k));
}

