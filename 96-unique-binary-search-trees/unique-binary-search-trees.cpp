class Solution {
public:
    int numTrees(int n) {
        vector<int > arr(n+1 , 0 ) ;
        arr[0] = 1 ;
        arr[1] = 1 ;
        for(int i = 2 ; i <= n ; i++ ){
            for(int j = 1 ; j<= i ; j++  ){
                int l = arr[j-1 ] ;
                int r = arr[i-j] ;
                arr[i] += l*r ;

            }
        }
        return arr[n] ;
    }
};