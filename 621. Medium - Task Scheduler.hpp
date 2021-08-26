class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)    return tasks.size();
        vector<int> dict(26,0);
        for(auto t:tasks)   dict[t-'A']++;
        
        auto base = *max_element(dict.begin(), dict.end());
        
        int total = (n+1)*(base-1);
        
        // for(auto d:dict){
        //     total += max(d-base+1, 0);
        // }
        for(auto d:dict){
            total -= min(d, base-1);
            total += d;
        }
        int count = tasks.size();
        total = max(total, count);
        
        return total;
    }
};