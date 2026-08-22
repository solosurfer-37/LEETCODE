class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 ; 
        int ans = n ;
        int product = 1 ; 
        while(n>0 ){
            sum = sum + n%10 ;
            product = product * (n%10) ;
            n = n/10 ;
        }
        sum += product ;
        if( ans%sum == 0 ){
            return true ;
        }
        return false ;

    }
};