/*

128. Longest Consecutive Sequence
Hard

5063

249

Add to List

Share
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


Constraints:

0 <= nums.length <= 104
-109 <= nums[i] <= 109


Follow up: Could you implement the O(n) solution?
Accepted
401,100
Submissions
859,221

*/
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        set<int> s;

      for(int i :a){
          s.insert(i);
      }

      int totalsize=0;

      for(int i:a ){
          if(!s.count(i-1)){
              int cur=i;
              int streak=1;

              while(s.count(cur+1)){
                  cur+=1;
                  streak+=1;
              }

              totalsize=max(totalsize,streak);
          }
      }
      return totalsize;


    }
};
