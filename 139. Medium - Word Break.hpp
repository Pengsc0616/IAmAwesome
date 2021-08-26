class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Dict(wordDict.cbegin(), wordDict.cend());
        
        int n = s.length();
        s = " "+s;
        vector<int> f(n+1,0);
        f[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=i; j++){
                if(f[j]==1){
                    if(Dict.count(s.substr(j+1,i-j))){
                        f[i]=1;
                        break;
                    }
                }
            }
        }
        return f[n];
    }
};