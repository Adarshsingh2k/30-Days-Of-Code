/*
1. Two Sum
Easy

29300

934

Add to List

Share
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
Accepted
5,975,848
Submissions
12,382,319

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         int start=0;
//         int end=nums.size()-1;
        
//         sort(nums.begin(),nums.end());
        
//         while(start<end){
//             if(nums[start]+nums[end]==target){
//                 out.push_back(start);
//                 out.push_back(end);
//                 break;
//             }
//             else if(nums[start]+nums[end]>target){
//                 end--;
//             }
//             else  start++;
//         }
        
        vector<int>out;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end()){
               out.push_back(map[target-nums[i]]);
                out.push_back(i); 
            }
            map[nums[i]]=i;
        }
        
        
        return out;
        
    }
};