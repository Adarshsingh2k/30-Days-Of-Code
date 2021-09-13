/*
46. Permutations
Medium

7436

148

Add to List

Share
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
Accepted
916,332
Submissions
1,324,094

*/

class Solution {
public:
    
    void recurUtil(vector <int>&ds,vector<int>& nums,vector<vector<int>> &ans,int freq[]){
        // base case when size od store ds=size of nums
        
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1; // makes array visited
                recurUtil(ds,nums,ans,freq);
                // when backtracking make remove the element from stor ds and mark freq array as 0
                freq[i]=0;
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        recurUtil(ds,nums,ans,freq);
        return ans;
        
    }
};