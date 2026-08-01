class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1 ) * (ay2 - ay1) ;
        int area2 = (bx2 - bx1 ) * (by2 - by1) ;
        
        int over_top = min(by2, ay2) ;
        int over_right = min(bx2,ax2) ;
        int over_bottom = max(by1 , ay1 ) ;
        int over_left = max(bx1 , ax1 ) ;

        int area3 = 0 ;
        if(over_right>over_left && over_top> over_bottom ){
            area3 = (over_right - over_left)*(over_top - over_bottom ) ;
        }
        return area1 + area2 - area3 ;
    }
};