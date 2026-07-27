// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int high = n, low = 0;
        while (high > low) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid;
            }

            else {
                low = mid + 1;
            }
        }
        return low;
        // int i = 1;
        // while(i<= n ){
        //     return isBadVersion(i) == 1 ;
        //     i++;
        // }
        // return 0 ;
    }
};