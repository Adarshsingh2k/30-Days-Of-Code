/*
Question Link
https://www.hackerearth.com/challenges/competitive/ptf-quicode-coding-challenge-4/algorithm/maximise-mismatch-0b42af4c/

*/

#include<bits/stdc++.h>
using namespace std;

int max_mismatch (int n, string s) {


    map<char,int>m;
    for(int i=0;i<n;i++){
        m[s[i]]++;

    }

    vector<int>v;

    int fin=0;
    
    for(auto x:m){
        //v.push_back(x.second);
        fin=abs(x.second-fin);
      
    }
    //cout<<fin<<endl;
  
    
    return n-fin;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        int out_;
        out_ = max_mismatch(N, S);
        cout << out_;
        cout << "\n";
    }
}