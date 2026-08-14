class Solution {
public:
    int maximumLengthSubstring(std::string s) {

        int count[26] = {0};
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < s.length(); ++right) {
            int right_char = s[right] - 'a';
            count[right_char]++;

            while (count[right_char] > 2) {
                int left_char = s[left] - 'a';
                count[left_char]--;
                left++;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};
