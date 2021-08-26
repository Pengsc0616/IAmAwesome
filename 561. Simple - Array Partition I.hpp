class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());  //nlog(n)
        
        int ans = 0;
        for(int i=0; i<nums.size(); i=i+2){
            ans += nums[i];
        }
        return ans;
    }
    
};