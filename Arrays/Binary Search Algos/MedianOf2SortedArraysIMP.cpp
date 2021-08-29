/*
4. Median of Two Sorted Arrays
Hard

12060

1660

Add to List

Share
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // go with the smaller array
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        
        // low =0 and high will be size of the smaleest array
        // because median will be near to it
        int low = 0, high = n1;
        
        
        while(low<=high){
            
            // part1 is partition of first array
            int part1= (low+high)>>1;
            
            //part 2 is partion or nuber of elemnt required from 2nd array
            int part2= ((n1+n2+1)/2)-part1;
            
            // l1,l2 are the left most biggest elemnts 
            // and r1,r2 are just opposite to l1 and l2
            int l1 = part1 == 0 ? INT_MIN : nums1[part1-1];
            int l2 = part2 == 0 ? INT_MIN : nums2[part2-1]; 
            
            int r1 = part1 == n1 ? INT_MAX : nums1[part1];
            int r2 = part2 == n2 ? INT_MAX : nums2[part2]; 
            
            
            // now the main check is agar left elemnt of first array is smaaler than right elemnt of 2nd array
            // and simmilrly for other half our condition is satisfied
            // else decreas high or increase low
            
            if(l1<=r2 and l2<=r1){
                 if( (n1 + n2) % 2 == 0 ) 
                    return (max(l1, l2) + min(r1, r2)) / 2.0; 
                else 
                    return max(l1, l2); 
            }
            
             else if(l1 > r2) {
                high = part1 - 1; 
            }
            else {
                low = part1 + 1; 
            }
        }
        
        return 0.0;
        
    }
};