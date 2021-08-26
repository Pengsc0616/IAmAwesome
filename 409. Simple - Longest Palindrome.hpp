class Solution {
public:
    int longestPalindrome(string s) {
        if(!s.size())   return 0;
        vector<int> cnt_array(128,0);
        
        for(const char c:s){
            cnt_array[c]++;
        }
        
        for(const int cnt:cnt_array){
            ans += cnt/2*2;
            if(cnt%2!=0)    odds = true;
        }
        if(odds)    ans++;
        return ans;
    }
private:
    int ans=0;
    bool odds=false;
};