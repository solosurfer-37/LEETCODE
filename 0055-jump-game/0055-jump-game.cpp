class Solution {
public:
    bool canJump(vector<int>& nums) {
        int Max = 0 ;
        for(int i = 0 ; i < nums.size() ; i++ ){
            if(i> Max){
                return false ;
            }

            Max = max(Max , i+ nums[i]);
            if(Max >= nums.size() -1){
                return true ;
            }
        }
        return true ;
    }
};