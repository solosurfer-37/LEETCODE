class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1 ;
        vector<int> ans(2, -1);
        while(high >= low ){
            int mid = low + (high - low)/2 ;
            if(nums[mid] == target ){
                int l = mid , r = mid; 
                while(l > 0 && nums[l-1] == target ) l-- ;
                while(r < nums.size()-1 && nums[r + 1] == target ) r++ ;
                ans[0] = l;
                ans[1] = r;
                break ; 
            }
            else if(nums[mid] > target ){
                high = mid-1 ;
            }
            else{
                low = mid+1 ;
            }
        }
        return ans ;
    }
};