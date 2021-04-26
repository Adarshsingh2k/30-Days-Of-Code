#include <bits/stdc++.h>

using namespace std;

void  reverseWord(string str){
    stack<char> s;

    for(int i=0;i<str.length();++i){
        //push the elements in stack untill
        //space is found

        if(str[i] != ' '){
            s.push(str[i]);
        }

        else{
            //while stack is not empty 
            //pop elements 

            while(!s.empty()){
                cout<<s.top();
                s.pop();
            }
            cout<< " ";
        }
        
    }

    //for the last word of the string 
    //ther will be no space so print it 

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

}

int main(){

    string str;
    cout<<" eneter tre string"<<endl;

    getline(cin,str);
    

    reverseWord(str);


}