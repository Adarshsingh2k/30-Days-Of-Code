/*
6. ZigZag Conversion
Medium

2859

6805

Add to List

Share
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
Accepted
643.6K
Submissions
1.6M
Seen this question in a real interview before?
*/

class Solution {
public:
    string convert(string s, int numRows) {
        
        // 1. vector mein har position mein same row ke element honge
        // poore ko ek saath nayi string mein daal do
        
        vector<string>v(numRows,"");
        
        int i=0;
        
        int n=s.length();
        
        while(i<n){
            // for first and last row
            for(int j=0;j<numRows and i<n;j++){
                v[j].push_back(s[i++]);
            }
            
            // for all rows except 1 and last , diagonal elements of roww also included
            for(int j=numRows-2;j>=1 and i<n;j--){
                v[j].push_back(s[i++]);
            }
            
        }
        
        string out="";
        for(auto x:v){
            out+=x;
        }
        
        return out;
        
    }
};