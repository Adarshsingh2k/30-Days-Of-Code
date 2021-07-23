#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2, int i,int j, vector<vector<int>> &dp){



	// base case
	if(i==s1.length() or j==s2.length()){
		return 0;
	}

	// if state is pre computed
	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	if(s1[i]==s2[j]){
		return dp[i][j]= 1+lcs(s1,s2,i+1,j+1,dp);
	}

	int op1=lcs(s1,s2,i+1,j,dp);
	int op2=lcs(s1,s2,i,j+1,dp);

	return dp[i][j]= max(op1,op2);
}


int main(){
	 string s1="ASD";

	 string s2="ASD";

	 int x=s1.length();
	 int y=s2.length();

	 vector<vector<int> >dp(x, vector<int>(y,-1));
	 cout<<lcs(s1,s2,0,0,dp)<<endl;
}