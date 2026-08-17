class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2, 1);
        int mn = INT_MAX;
        for (int i = sqrt(area) ; i > 0 ; i-- ) {
                if (area % i == 0 ) {
                    ans[0] = area / i;
                    ans[1] = i;
                    return ans ;
                }
        }
        return {area, 1};;
    }
};