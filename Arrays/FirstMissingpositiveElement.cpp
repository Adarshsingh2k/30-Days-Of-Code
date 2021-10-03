/*
41. First Missing Positive
Hard

7224

1135

Add to List

Share
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
Accepted
558,475
Submissions
1,592,544
Seen this question in a real interview before?

Yes

No


*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // 1. check all numbers are in range of 1 to n else mark the element out of range element as 1
        //    and also check if there is one already present in array
        // 2. Now do mapping- for each element check if nums[element-1] exist ; equate it to -nums[element-1]
        // 3. Now check array for first positive occurence if we get any positive element return i+1 as its missing element
        // aisa issliye kyunki agar koi element present nahi hoga toh humko uske index position pe -ve element nahi milega
        // 4. else return n+1
        
        bool one=false;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==1) one=true;
            
            if(nums[i]<1 or nums[i]>n) nums[i]=1;
        }
        
        if(one==false) return 1;
        
        for(int i=0;i<n;i++){
            int idx=abs(nums[i]);
            nums[idx-1]=-abs(nums[idx-1]);
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }
        
        return n+1;
    }
};