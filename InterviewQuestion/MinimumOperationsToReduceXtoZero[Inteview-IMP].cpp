/*
1658. Minimum Operations to Reduce X to Zero

---> https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/1445347/Minimum-Operations-to-Reduce-X-to-Zero-C%2B%2B
---> https://www.youtube.com/watch?v=7nzwrX4N_A0

Medium

1177

21

Add to List

Share
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        int sum=0;
        // find the sum of arr
        for(int i=0;i<n;i++) sum+=nums[i];
        
        // agar poore array ka sum target se chota hai 
        // tab answer possible nahi hai
        
        if(sum<x){
            return -1;
        }
        
        // now we will use concept of maximizing subaaray
        // and thi subarr is our new target
        // agar hum andar ka size bada krdenge toh bhaar ke elements kam hojaaenge
        int target=sum-x;
        
        if(target==0) return n;
        
        int curSum=0, res=INT_MIN;
        
        unordered_map<int,int>mp;
        // when sum is 0 its important to initialize it
        mp[curSum]=-1;
        
        for(int i=0;i<n;i++ ){
            
            // har ek sum ko map pe index ka saath add kroo
            curSum+=nums[i];
            
            // agar map mein humme target element - curSum  jo bhi aata hai
            // agar mil jaata hai toh hum uss particular index se leke current elemnt ke index ka distance dekhenge jo humme
            // number of elements dega
            if(mp.find(curSum-target)!=mp.end()){
                res=max(res,i-mp[curSum-target]);
            }
            
            mp[curSum]=i;
            
        }
        if(res==INT_MIN) return -1;
        return n-res;
        
        
        
    }
};