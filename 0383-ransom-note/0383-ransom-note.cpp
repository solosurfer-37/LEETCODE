class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int CHARR[26] = {0} ;

        for(int i = 0 ; i < magazine.length() ; i++ ){
            CHARR[magazine[i] - 'a']++ ;
        }
        for(int i = 0 ; i < ransomNote.length() ; i++ ){
            if(--CHARR[ransomNote[i] - 'a'] < 0 ){
                return false ;
            }
        }

        return true ;
    }
};