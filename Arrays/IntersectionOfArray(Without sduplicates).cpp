class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s(nums1.begin(),nums1.end());
        vector<int>out;
        for(auto x: nums2){
            if(s.find(x)!=s.end()) {
                out.push_back(x);
                s.erase(x);
                
            }
        }
        return out;
    }
};