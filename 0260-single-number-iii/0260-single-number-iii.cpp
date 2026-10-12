class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int , int > aloo ;
        vector<int > ans ;
        for(int i = 0 ; i < nums.size() ; i++ ){
             aloo[nums[i]]++ ;
        }
        for(auto it = aloo.begin() ; it != aloo.end() ; it++ ){
            if(it->second == 1 ){
                ans.push_back(it->first) ;
            }
        }
        return ans ;
    }
};