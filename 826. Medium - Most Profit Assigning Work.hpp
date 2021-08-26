class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>> m_;
        for(int i=0; i<difficulty.size(); i++){
            m_.emplace_back(difficulty[i], profit[i]);
        }
        sort(m_.begin(), m_.end(), [](const auto & a, const auto & b){
            return a.first < b.first;
        });
        
        sort(worker.begin(), worker.end(), [](const auto & a, const auto & b){
            return a<b;
        });
        
        int maxProfit = 0;
        int index = 0;
        int ans = 0;
        for(auto w:worker){
            while(index<m_.size() && m_[index].first<=w){
                maxProfit = max(maxProfit, m_[index].second);
                index++;
            }
            ans += maxProfit;
        }
        return ans;
    }
};



















