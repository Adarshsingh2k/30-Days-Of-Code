/*
740. Delete and Earn
Medium

2362

163

Add to List

Share
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
Accepted
81.2K
Submissions
152.8K

*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        // basic concept hai kya exclude krnaa hai aur kya include krnaa hai
        // har number ko yaa toh include krenge ya exclude krenge
        // pehle ek frequency array bnaa lo
        // abb max Points ke liye peechle waale ko ya toh include kroge yaa nahi
        
        
        int n=10001;
        vector<int>freq(n,0);
        
        for(int x:nums){
            freq[x]++;
        }
        
        int include=0,exclude=0;
        
        
        
        for(int i=0;i<n;i++){
            
            // for include we can total points of current element aur usse
            // pehle waale ko exclude krke jitna tha unka sum
            int takeInc=exclude+freq[i]*i;
            
            // for exclude abb humme present element lena hi nahi aur 
            //question ke hisaaab se max element lena hai
            // toh usse pehle waale element ke [include,exclude] mein jo max hai woh lel0
            int takeExc=max(include,exclude);
            include=takeInc;
            exclude=takeExc;
        }
        
        return max(include,exclude);
            
        
    }
};