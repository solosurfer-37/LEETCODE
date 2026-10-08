class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> aloo;
        for (int i = 0; i < nums.size(); i++) {
            if (aloo.count(nums[i])) {
                if (i - aloo[nums[i]] <= k) {
                    return true;
                }
            }
            aloo[nums[i]] = i;
        }
        return false;
    }
};