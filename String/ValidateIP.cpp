/*
                        Validate an IP Address 
                        
Medium Accuracy: 29.04% Submissions: 61568 Points: 4
Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function takes a string s as its only argument .

Example 1:

Input:
ip = 222.111.111.111
Output: 1
Example 2:

Input:
ip = 5555..555
Output: 0
Explanation: 5555..555 is not a valid
ip address, as the middle two portions
are missing.
Your Task:
Complete the function isValid() which takes the string s as an input parameter and returns 1 if this is a valid ip address otherwise returns 0.

Expected Time Complexity: O(N), N = length of string.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of string <=50

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Company Tags
 Amazon Microsoft Qualcomm Zoho

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            
            int dot=0;
            
            for(int i=0;i<s.size();i++){
                if(s[i]=='.'){
                    dot++;
                }
            }
            
            if(dot!=3){
                return 0;
            }
            
            stringstream ss(s);
            string temp;
            
            while(getline(ss,temp,'.')){
                
                int n=temp.size();
                
                //if size of temp more than 3 or is 0 than ip cant be validated
                if(n==0 or n>3){
                    return 0;
                }
                //it checks 025.0.0.0 agaar aisi koi condition jisme number 1 degit
                // se bada hai par starting digit 0 hai toh false
                if(n>1 and temp[0]=='0'){
                    return 0;
                }
                
                int ipPart=0;
                
                for(int i=0;i<n;i++){
                    //checks for number to be a integer
                    if(temp[i]>='0' and temp[i]<='9'){
                        ipPart=ipPart*10+(temp[i]-'0');
                    }
                    else return 0;
                }
                
                if(ipPart>=0 and ipPart<=255){
                    continue;
                }
                else return 0;
                
                
            }
            
            
            return 1;
            
            
            
           
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends