
class Solution {
public:
    string maxValue(string n, int x) {
        char target = '0' + x;
        int len = n.length();
        
        for (int i = 0; i < len; ++i) {
            if (n[0] == '-' && i == 0) continue;
            if ((n[0] == '-' && n[i] > target) || (n[0] != '-' && n[i] < target)) {
                return n.substr(0, i) + target + n.substr(i);
            }
        }
        return n + target;
    }
};