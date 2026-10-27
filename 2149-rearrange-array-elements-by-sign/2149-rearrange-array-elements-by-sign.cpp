class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg ;
        vector<int> pos ;
        for(int i = 0 ; i < nums.size() ; i++ ){
            if( nums[i] <= 0 ){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        vector<int> ans ;
        for(int i = 0 , j = 0 ; i < pos.size() && j< neg.size() ; i++ , j++ ){
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
        }
        return ans ;
    }
};