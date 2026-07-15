class Solution {
public:  
    void get(vector<int>& candidates, int target , int i , vector<int>&sum , vector<vector<int>> &answer ){
        if(target ==0 ){
            answer.push_back(sum ) ; 
            return ; 
        }
        if(target< 0 || i == candidates.size() ){
            return ; 
        }
        if(candidates[i] <= target ){
            sum.push_back(candidates[i]) ;
            get(candidates , target - candidates[i], i ,sum , answer );
            sum.pop_back() ;
        }
        get(candidates , target  , i+1 , sum , answer ) ;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sum ;
        vector<vector<int>> answer ;
        get(candidates , target , 0 , sum ,answer );
        return answer ;
    }
};