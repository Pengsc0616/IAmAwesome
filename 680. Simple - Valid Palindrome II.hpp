class Solution {
public:
    bool validPalindrome(string s) {
        if(!s.size())   return true;
        for(int i=0, j=s.size()-1; i<j; i++,j--){
            if(s[i]!=s[j]){
                return (subPalindrom(s,i,j-1)||subPalindrom(s,i+1,j));
            }
        }
        return true;
    }
private:
    bool subPalindrom(string s, int i, int j){
        for(; i<j; i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
};