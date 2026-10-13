class Solution {
public:
    char findTheDifference(string s, string t) {
        sort( s.begin() , s.end() );
        sort( t.begin() , t.end() );
        int size = t.size();
        for(int i = 0 ; i < size ;i++ ){
            if(t[i] != s[i]){
                return t[i] ;
            }
        }
        return '\0' ;
    }
};