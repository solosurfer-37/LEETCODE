class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }

        vector<pair<char, int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        string out = "";
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].second; j++) {
                out.push_back(v[i].first);
            }
        }

        return out;
    }
};