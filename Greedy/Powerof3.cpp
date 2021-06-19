/*
Power of 3 
Easy Accuracy: 67.38% Submissions: 698 Points: 2
Given a number N, the task is to count the numbers in the range [1, N] which can be represented as power of 3.

Note: 1 can be represented as the power of 3.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two integers N.


Output: For each test case, print the answer

Constraints:
1. 1 <= T <= 104
2. 1 <= N <= 109

Example:
Input:
2
6
1

Output:
2
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n;
	    cin>>n;
	    
	    int cnt=0;
    	//int i=0;
   
    
    	cout << (int) ((log (n))/(log (3))) +1 << endl;

	    
	}
	
	
	
	return 0;
}