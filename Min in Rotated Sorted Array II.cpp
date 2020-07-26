class Solution {
public:
    // Binary Search O(logn) approach 
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<right) {
            int mid = left + (right-left)/2;
            if(nums[mid]==nums[right]){
                if(nums[mid]==nums[left]){
                    left = left+1;
                }
                else 
                    right = mid;
            }
            else if(nums[mid]>nums[right])
                left = mid+1;
            else 
                right = mid;
        }  
        return nums[left];
    }
};
