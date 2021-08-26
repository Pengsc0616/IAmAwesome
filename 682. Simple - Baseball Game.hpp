class Solution {
public:
    int calPoints(vector<string>& ops) {
        for(const string s: ops){
            if(s=="C"){
                ans.pop_back();
            }
            
            else if(s=="D"){
                ans.push_back(2*ans[ans.size()-1]);
            }
            
            else if(s=="+"){
                ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
            }
            
            else{
                ans.push_back(stoi(s));
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
private:
    vector<int> ans;
};