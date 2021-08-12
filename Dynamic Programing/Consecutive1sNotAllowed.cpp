/*
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    
	    // stores count of ones
	    ll c1=1;
	    // stores count of 0
	    ll c0=1;
	    
	    // So basically what are we doing is
	    // we will be keeping count of all ones that follow our condition
	    // and all the 0s that follow our condition
	    // ways(0)= all the strings that are possible with  0 and 1
	    // and ways(1) = all the strings possible with 0
	    // final count will be all ways(0)+ways(1);
	    
	    
	    for(int i=2;i<=n;i++){
	        // store the new counts of 0 and 1
	        ll n1=c0;
	        ll n0=c0+c1;
	        
	        c0=n0%1000000007;
	        c1=n1%1000000007;
	    }
	    
	    return (c0+c1)%1000000007;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    
	    // stores count of ones
	    ll c1=1;
	    // stores count of 0
	    ll c0=1;
	    
	    // So basically what are we doing is
	    // we will be keeping count of all ones that follow our condition
	    // and all the 0s that follow our condition
	    // ways(0)= all the strings that are possible with  0 and 1
	    // and ways(1) = all the strings possible with 0
	    // final count will be all ways(0)+ways(1);
	    
	    
	    for(int i=2;i<=n;i++){
	        // store the new counts of 0 and 1
	        ll n1=c0;
	        ll n0=c0+c1;
	        
	        c0=n0%1000000007;
	        c1=n1%1000000007;
	    }
	    
	    return (c0+c1)%1000000007;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends