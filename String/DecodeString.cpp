/*
394. Decode String
Medium

8697

376

Add to List

Share
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
Accepted
522,195
Submissions
919,513
*/

class Solution {
public:
    string recurDecode(string s,int&pos){
        int n=s.size(),num=0;
        string ans="";
        for(;pos<n;pos++){
            char cur=s[pos];
            if(isalpha(cur))ans+=cur;
            else if(isdigit(cur)) num=num*10+cur-'0';
            else if(cur ==']') return ans;
            else {
                string tmp=recurDecode(s,++pos);
                while(num--)ans+=tmp;
                num=0;
            }
        }
        
        return ans;
    }
    string decodeString(string s) {
        // stack<char>st;
        // for(int i=s.size()-1;i>=0;i--){
        //     st.push(s[i]);
        // }
        // string out="";
        // for(auto i:st){
        //     int tp=st.top();
        //         st.pop();
        //     if(tp=)
        // }
        int i = 0;
        return recurDecode(s, i);
    }
};