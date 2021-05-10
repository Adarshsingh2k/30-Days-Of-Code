/*
            31. Next Permutation
Medium

5515

1885

Add to List

Share
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.



Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
Accepted
512,063
Submissions
1,506,242
*/

/*class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //cout<<next_permutation(nums.begin(),nums.end());

        int n=nums.size();
       /* int k,l;
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }

        //if no breakpoint
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(l=n-1;l>k;l--){
                if(nums[l]>nums[k]){
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }

        int idx=-1;

        // start traversing from back

        for(int i=n-1;i>=0;i--){

            // abb agar ith element  i-1 se bada hai
            //toh break the loop and uss element
            //ka idx storee krro

            if(nums[i]>nums[i-1]){
                idx=i;
                break;
            }

        }

        if(idx==-1){
            reverse (nums.begin(),nums.end());
        }

        // abb hume check krna hai ki last idx
        //se leke array ke end tak aisa konsa
        //element hai jo (idx-1) se chota hai

        else{
            int prev=idx;
            for(int i= idx+1;i<n;i++){
                if(nums[i]>nums[idx-1] and nums[i]<=nums[prev]){
                    prev=i;
                }
            }
            //abb idx-1 aur jousse just bada element ahi usko swap krdo
            swap(nums[idx-1],nums[prev]);
            reverse(nums.begin()+idx,nums.end());


        }




    }
};
*/


class Solution {
public:
    void nextPermutation(vector<int>& a) {
       int idx=-1;
        int n=a.size();

        for(int i=n-1;i>0;i--){
            if(a[i]>a[i-1]){
                idx=i;
                break;
            }
        }

        if(idx==-1){
            reverse(a.begin(),a.end());
        }

        else{
           int prev=idx;
            for(int i=idx+1;i<n;i++){
                if(a[i]>a[idx-1] and a[i]<=a[prev]){
                    prev=i;
                }
            }
            swap(a[idx-1],a[prev]);
        reverse(a.begin()+idx,a.end());
        }


    }
};
