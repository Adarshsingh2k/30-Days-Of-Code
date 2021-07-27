/**

Nearly Sorted Algorithm 
Medium Accuracy: 52.22% Submissions: 26467 Points: 4
Given an array of n elements, where each element is at most k away from its target position. The task is to print array in sorted form.

Input:
First line consists of T test cases. First line of every test case consists of two integers N and K, denoting number of elements in array and at most k positions away from its target position respectively. Second line of every test case consists of elements of array.

Output:
Single line output to print the sorted array.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N

Example:
Input:
2
3 3
2 1 3
6 3
2 6 3 12 56 8
Output:
1 2 3
2 3 6 8 12 56*
*/

#include <bits/stdc++.h>
using namespace std;

// stps to perform
/*
    1. Maintain a min heap of size K
    2. Push elemnst of array to  min heap 
    3. iF  size of min heap is more than K
    4. pop the top element of heap to vector
    5. Now keep poping the rest elemnt of heap
    

*/

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    vector<int>v;
	    priority_queue<int, vector<int>, greater<int>>pq;
	    
	    for(int i=0;i<n;i++){
	        pq.push(a[i]);
	        
	        // if size more than k pop the top element as it will
	        // be the smallest element in the heap and according to K sorted alfgo
	        // the elemnt will bwe in the range of [-k,+k]
	        if(pq.size()>k){
	            v.push_back(pq.top());
	            pq.pop();
	        }
	        
	        
	    }
	    while(!pq.empty()){
	        v.push_back(pq.top());
	        pq.pop();
	    }
	    
	    for(int i=0;i<n;i++){
	        cout<<v[i]<<" ";
	    }
	    
	 cout<<endl;   
	}
	return 0;
}