class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m_(26,0);
        for(auto s:s1){
            m_[s-'a'] ++;
        }
        
        vector<int> n_(26,0);
        int count = 0;
        for(int i=0; i<s2.size(); i++){
            n_[s2[i]-'a']++;
            count++;
            if(count > s1.size()){
                n_[s2[i-s1.size()]-'a']--;
                count--;
            }
            if(m_ == n_)    return true;
        }
        return false;
    }
};