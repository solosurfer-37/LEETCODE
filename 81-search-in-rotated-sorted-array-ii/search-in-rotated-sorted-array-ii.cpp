class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1 ;
        sort(nums.begin() , nums.end() ); 
        while(high >= low ){
            int mid = low + (high - low )/2 ;
            if(nums[mid ] == target ){
                return true ;
            }
            else if( nums[mid] > target ){ high = mid-1 ;}
            else{low = mid + 1 ; }
        }
        return false ;
    }
};