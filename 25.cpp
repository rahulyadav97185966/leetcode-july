//Find Minimum in Rotated Sorted Array II

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l  = 0 , r = nums.size()-1, mid;
        
        while(l < r){
            mid = l  + (r-l)/2;
            
            if(nums[mid] == nums[r]){
                if(nums[mid] == nums[l]){
                    l = l + 1;
                }
                else r = mid;
            }
            else if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else r = mid ;
        }
        
        return nums[l];
    }
};
