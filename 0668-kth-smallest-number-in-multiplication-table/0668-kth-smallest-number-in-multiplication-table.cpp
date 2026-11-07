class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> ans ;
        int low = 1 ; 
        int high = m* n ;
        
        while(low < high){
            int count = 0 , mid = low + (high - low) / 2 ;
            for(int i = 1 ; i <= m ; i++ ){
                count += min(mid/i , n );
            }

            if(count < k ){
                low = mid+1 ;
            }

            else{
                high = mid ;
            }
        }
        return low ;
    }
};