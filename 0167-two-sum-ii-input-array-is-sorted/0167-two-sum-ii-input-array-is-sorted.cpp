class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_set<int> aloo;

        for (int i = 0; i < numbers.size(); i++) {
            int c = target - numbers[i];
            if (aloo.count(c)) {
                for (int j = 0; j < i; j++) {
                    if (numbers[j] == c) {
                        return {j + 1, i + 1};
                    }
                }
            }
            aloo.insert(numbers[i]);
        }

        return {};
    }
};