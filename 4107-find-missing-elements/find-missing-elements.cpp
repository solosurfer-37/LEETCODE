class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {} ;
        sort(nums.begin() , nums.end() ) ;
        vector<int> ans ;
        int size = nums.size() ;
        int answer = nums[0] ;
        for(int i = 0 ; i < size ; i++ ){
            while (answer < nums[i]) {
                ans.push_back(answer);
                answer++;
            }
            answer = nums[i] + 1 ;
        }

        return ans ;
    }
};