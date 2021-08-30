/*
34. Find First and Last Position of Element in Sorted Array
Medium

6945

230

Add to List

Share
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    
    int check(vector<int>& nums, int target){
        int low=0,high=nums.size()-1;
        
        int firstBest=nums.size();
        
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]>=target){
                // agar yea condition true hai toh yea pehli position
                // hogi jahan pe umko desired element milega
                firstBest=mid;
                // abb agar element bada hua x se ya x hi hua tab bhi uske 
                // left mein x mil sakta hai jo humar apehla ocuurence hoga x ka
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }
        }
        return firstBest;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // abb for first occurence we will check for target
        int first=check(nums,target);
        // last occcurence target element se jo bada element 
        // hoga usse ek index pehle hogi
        int last= check(nums,target+1)-1;
        
        if(first<= last) return {first,last};
        return{-1,-1};
    }
};