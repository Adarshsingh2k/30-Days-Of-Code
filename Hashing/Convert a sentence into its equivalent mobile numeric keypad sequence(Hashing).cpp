// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string printSequence(string s)
{
    //code here.
    
    map<string,int>mp;
    mp["ABC"]=2;mp["DEF"]=3;
    mp["GHI"]=4;mp["JKL"]=5;
    mp["MNO"]=6;mp["PQRS"]=7;
    mp["TUV"]=8;mp["WXYZ"]=9;
    
    map<char,pair<int,int>>freq;
    
    for(auto &e:mp){
        for(int i=0;i<e.first.length();i++){
            freq.insert({e.first[i],make_pair(e.second,i+1)});
        }
    }
    
    string ans="";
    
    for(int i=0;i<s.length();i++){
        if(s[i]==' ')ans+="0";
        else{
            int num = freq[s[i]].first;
            int f = freq[s[i]].second;
            string temp= to_string(num);
            for(int j=0;j<f;j++)ans+=temp;
        }
        
       
    }
    
    return ans;
    
}