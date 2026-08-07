class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0 , size = word.size();
        for (int i = 0; i < size ; i++) {
            if (isupper(word[i])) {
                count++;
            }
        }
        if (count == size || count == 0) return true;
        if (count == 1 && isupper(word[0])) return true;
        return false;
    }
};