class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        int size = *max_element(nums.begin(), nums.end());
        vector<int> map(size+1, 0);
        for(auto n: nums){
            map[n] += n;
        }
        return DP(map);
        
    }
    
private:
    int DP(vector<int> & map){
        vector<int> dp(map.size(),0);
        dp[0] = map[0];
        dp[1] = max(map[0],map[1]);
        
        for(int i=2; i<map.size(); i++){
            dp[i] = max(dp[i-2]+map[i], dp[i-1]);
        }
        return dp[map.size()-1];
    }
};