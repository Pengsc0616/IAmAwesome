class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        -2,1,-3,4,-1,2,1,-5,4
        -=                      -2 -2
        -2 1 -3 4  3 5 6  1 5  
        */
        int n_max = nums[0];
        vector<int> ans(nums.size(), 0);
        ans[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            ans[i] = max(nums[i], ans[i-1]+nums[i]); 
                //the max substr sum if I must include ans[i]
            n_max = max(n_max, ans[i]);
        }
        return n_max;
    }
};