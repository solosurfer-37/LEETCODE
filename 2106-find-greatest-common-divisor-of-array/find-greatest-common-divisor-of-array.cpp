class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums[nums.size() - 1];
        int i = 0;
        for (int i = min; i >= 1; --i) {
            if (max % i == 0 && min % i == 0) {
                return i;
            }
        }
        return 1;
    }
};