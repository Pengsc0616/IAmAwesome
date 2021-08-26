class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(!intervals.size())   return {};
        sort(intervals.begin(),intervals.end(),[](auto a, auto b){
            return a[0]<b[0];
        });
        
        
        vector<vector<int>> ans;
        
        for(auto inter:intervals){
            if(!ans.size() || inter[0]>ans.back()[1]){
                ans.push_back(inter);
            }
            else{
                ans.back()[1] = max(inter[1], ans.back()[1]);
            }
        }
        return ans;
    }
};