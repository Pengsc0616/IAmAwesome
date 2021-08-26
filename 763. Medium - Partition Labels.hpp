class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> dict(26, 0); //{end}
        
        for(int i=0; i<s.size(); i++){
            dict[s[i]-'a'] = i;
        }
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            int start = i;
            int max = dict[s[i]-'a'];
            // cout << max << " ";
            for(;i<max;i++){
                if(dict[s[i]-'a']>max)  max = dict[s[i]-'a'];
                // cout << max << " ";
            }
            // cout << max-start+1 << endl;
            ans.push_back(max-start+1);
        }
        return ans;
    }
};