class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int,int>m;
        vector<int>out;
        int s1=nums1.size();
        int s2=nums2.size();
//         for(int i=0;i<s1;i++){
//             m[nums1[i]]++;
//         }
//         for(int i=0;i<s2;i++){
//            if(m[nums2[i]]>0){
//                m[nums2[i]]--;
//                out.push_back(nums2[i]);
//            }
//         }
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<s1 and j<s2){
            if(nums1[i]==nums2[j]){
                
                out.push_back(nums1[i]);i++;j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
        }
            
        
        
        return out;
    }
};