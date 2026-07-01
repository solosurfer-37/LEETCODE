#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hours_spent = 0;
            
            for (int pile : piles) {
                hours_spent += (pile + mid - 1) / mid; 
            }
            
            if (hours_spent <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
