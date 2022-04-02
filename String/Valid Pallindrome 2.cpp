/*
680. Valid Palindrome II
Easy

5215

283

Add to List

Share
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
Accepted
462,431
Submissions
1,179,976

*/

class Solution {
public:
  
    bool ispalindrome(string s, int i, int j){
        while(i < j){
            if(s.at(i) == s.at(j)){
                i++;
                j--;
            }else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
//         string newStr=s;int count=0;
//         reverse(s.begin(),s.end());
//         // if(s==newStr) return true;
//         else{
            
//             reverse(s.begin(),s.end());
//             for(int i=0;i<s.length();i++){
//                 if(s[i]!=newStr[i]) count++;
//             }
//         }
       
//         if(count>1 ) return false;
//         else return true;
        
         int i  = 0;
        int j = s.size()-1;
        while(i < j){
            if(s.at(i) == s.at(j)){
                i++;
                j--;
            }else{
                return ispalindrome(s, i+1, j) || ispalindrome(s, i, j-1);
            }
        }
        return true;
    }
};