class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> aloo;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            aloo[nums1[i]]++;
        }
        unordered_set<int> jeera;
        for (int i = 0; i < nums2.size(); i++) {
            if (aloo[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                aloo[nums2[i]]--; 
            }
        }
        return ans;
    }
};