class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        int i =0 ,j=0 ;
        char out[200]= "";
        for(j =0 ;j< strs[0].size() ;j++){
            for(int k = 1 ;k < size  ;k++){
                if(strs[k][j] != strs[0][j]){
                return out ;
                }
            }
            out[j] = strs[0][j];
        }            
        return out ;
    }
};