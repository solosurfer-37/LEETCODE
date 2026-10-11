class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = ratings.size() ;
        vector<int > ans(total , 1 ) ;
        for(int i = 1 ; i < total ; i++ ){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1] + 1 ;  
            }

        }
        for(int i = total-2 ; i >= 0  ; i-- ){
            if(ratings[i] > ratings[i+1]){
                ans[i] = max(ans[i] , ans[i+1]+1 );
            }
        }
        total = 0 ;
        for(int i = 0 ; i < ans.size() ; i++ ){
            total = total+ans[i] ;
        }
        return total ;
    }
};