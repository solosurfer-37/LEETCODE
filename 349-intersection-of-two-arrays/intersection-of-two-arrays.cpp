class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> aloo;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            aloo.insert(nums1[i]);
        }
        unordered_set<int> jeera;
        for (int i = 0; i < nums2.size(); i++) {
            if (aloo.count(nums2[i])) {
                ans.push_back(nums2[i]);
                aloo.erase(nums2[i]);
            }
        }

        return ans;
    }
};