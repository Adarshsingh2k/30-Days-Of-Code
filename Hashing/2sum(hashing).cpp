/*
        1. Two Sum (hashing)
Easy

20831

728

Add to List

Share
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
Accepted
4,207,037
Submissions
8,975,371

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;

        unordered_map<int,int>m;

        //basically we will push elements in map
        //and for every entry we will check that target - num[i]
        // map hai ki nahi agra hai toh uss position ko print krdenge
        //nahi toh uss particular element ko map me
        //index ke saath store krdenge
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()){
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
            }
               m[nums[i]]=i;
        }

        return v;

    }
};
