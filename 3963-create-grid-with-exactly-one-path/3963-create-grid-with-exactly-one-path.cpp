class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> aloo(m, string(n, '#'));
        for (int j = 0; j < n; j++) {
            aloo[0][j] = '.';
        }
        for (int i = 0; i < m; i++) {
            aloo[i][n - 1] = '.';
        }
        return aloo;
    }
};