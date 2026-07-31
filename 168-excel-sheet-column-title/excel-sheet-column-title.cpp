#include <string>
#include <algorithm>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--; 
            char currentChar = 'A' + (columnNumber % 26);
            result += currentChar;
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};