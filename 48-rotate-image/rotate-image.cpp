class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0 , j = 0 ;
        int size = matrix.size() ;
        for(i=0 ; i < size ; i++ ){
            for(j= i  ; j< size ; j++ ){
                swap(matrix[i][j] , matrix[j][i]);
            }   
        }
        for ( i = 0; i < size; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};