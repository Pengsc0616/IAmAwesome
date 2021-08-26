class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        10 9 2 5 3 7 101 18
        1. 1 1 2 2 3 4.  3.  
        */
        vector<int> ans(nums.size(),0);
        ans[0] = 1;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    ans[i] = max(ans[i],ans[j]);
                }
            }
            ans[i]++;
        }
        return *max_element(ans.begin(),ans.end());
    }
};