class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int ans{0};
        int g_itr=0;
        
        for(int s_itr=0; s_itr<s.size(); s_itr++){
            if(s[s_itr]>=g[g_itr]){
                ans++;
                if(g_itr+1==g.size()){
                    break;
                }
                g_itr++;
            }
        }
        return ans;
    }
};