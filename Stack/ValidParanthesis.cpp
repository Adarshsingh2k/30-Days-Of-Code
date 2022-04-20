/*
20. Valid Parentheses
Easy

12589

558

Add to List

Share
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
Accepted
2,165,054
Submissions
5,297,799
Seen this question in a real interview before?

Yes

No

*/

class Solution {
public:
    bool isValid(string s) {
//         stack<char> stk;
//         int i=1;
//         stk.push(s[0]);
//         while(i<s.length()){
//             if(s[i]==')' and stk.top()=='('){
//                 stk.pop();
//                 i++;
//             }
//             else if(s[i]=='}' and stk.top()=='{'){
//                  stk.pop();
//                 i++;
//             }
//             else if(s[i]==']' and stk.top()=='['){
//                  stk.pop();
//                 i++;
//             }
//             else{
//                 stk.push(s[i]);
//                 i++;
//             }
//         }
        
//         if(stk.empty()) return true;
//         else return false;
        
         stack<char> st;
    for(char c : s){
        if(c == '('|| c == '{' || c == '['){
            st.push(c);
        }else{
            if(st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            if(c == '}' && st.top() != '{') return false;
            if(c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
        
    }
};