class Solution {
public:
    void get(vector<int> &candidates, int target , int i ,vector<vector<int>> &ans , vector<int>&sum ){
        if(target == 0 ){
            ans.push_back(sum ) ;
            return ;
        }
        if(i == candidates.size() || target < 0) return ;
        if (candidates[i] <= target){
            sum.push_back(candidates[i]) ;
            get(candidates , target - candidates[i] , i , ans , sum ) ;
            sum.pop_back() ;
        }
        get(candidates , target , i+1 , ans , sum ) ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sum ;
        vector<vector<int>> ans ;
        get(candidates, target , 0 , ans , sum ) ;
        return ans ; 
    }
};