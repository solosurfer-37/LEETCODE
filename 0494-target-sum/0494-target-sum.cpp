class Solution {
public:
    int countways(vector<int>& nums , int target , int index , int current ){
        if(index == nums.size() ){
            return (current == target ) ? 1:0 ;
        }
        int add = countways(nums , target , index+1 , current + nums[index]);

        int subtract = countways(nums , target , index+1 , current -nums[index]);
        return add + subtract ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countways(nums , target , 0 , 0 );
    }
};