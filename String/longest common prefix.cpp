/*
    
                14. Longest Common Prefix
Easy

4282

2265

Add to List

Share
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        int mi=INT_MAX;
        string c=str[0];
        
        if(str.size()==0) return "";
        
        for(int i=1;i<str.size();i++){
            int j=0;
            int k=0;
            int common =0;
            
            while(j<c.size() and k<str[i].size()){
                if(c[j]==str[i][k]) common++;
                else break;
                
                j++;
                k++;
                
            }
            
            mi=min(mi,common);
            
        }
        
        return c.substr(0,mi);
        
        
        
        
    }
};