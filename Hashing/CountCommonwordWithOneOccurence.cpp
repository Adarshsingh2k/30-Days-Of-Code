/*
2085. Count Common Words With One Occurrence
Easy

374

8

Add to List

Share
Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

 

Example 1:

Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
Explanation:
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.
Example 2:

Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
Output: 0
Explanation: There are no strings that appear in each of the two arrays.
Example 3:

Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".
 

Constraints:

1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] and words2[j] consists only of lowercase English letters.
Accepted
28,216
Submissions
40,373
*/
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>m;
        for(int i=0;i<words1.size();i++){
            m[words1[i]]++;
        }
        int cnt=0;
        for(auto i=0;i<words2.size();i++){
           if(m[words2[i]]==1){
               // cnt++;
               // m.erase(words2[i]);
               m[words2[i]]--;
           }
            else m[words2[i]]=-1;
        }
        for(auto i:m){
            if(i.second==0)cnt++;
        }
        
        return cnt;
    }
};