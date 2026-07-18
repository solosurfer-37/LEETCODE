class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int  ,int > aloo ;
        for(int i = 0 ; i < nums.size() ; i++ ){
            aloo[nums[i]] ++ ;
        }
        for(auto it = aloo.begin() ; it != aloo.end() ; it++ ){
            if(it->second < 3 ){
                return it->first ;
            }
        }
        return 0 ;
    }
};