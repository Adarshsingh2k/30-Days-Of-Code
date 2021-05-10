class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        int sum=0;

        int x,y;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        x=0;
        y=n-1;
        while(x<y){


            sum=nums[x]+nums[y];
            if(sum>target){
                y--;

            }
            else if(sum<target){
                x++;
            }
            else if(sum==target){
                v.push_back(x);
                v.push_back(y);
                break;
            }
        }

        return v;

    }
};
