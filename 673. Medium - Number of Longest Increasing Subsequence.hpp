class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        /*
        1 3 5 4 7 6 2 5 6 8
        1 2 3 3 4 4 2 4 5 6
        1 1 1 1 2 2 1 1 1 1
        */
        /*
        1 3 5 4 7 6 2 5 6 8
        1 2 3 3 4 4 2 4 5 5
        1 1 1 1 2 2 1 1 1 5
        */
        //把長度剪一的length通通加起來 就是這一個新的length的count
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> ans(n,1);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                // cout << "num" << nums[j] << " " << nums[i]<<endl;
                if(nums[j]>=nums[i]) continue;
                if(dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    ans[i] = ans[j];
                }
                else if(dp[j]+1==dp[i]){
                    ans[i] += ans[j];
                }
            }
        }
        // for(auto d:dp){
        //     cout << d << " ";
        // }
        // cout << endl;
        // for(auto a:ans){
        //     cout << a << " ";
        // }
        int max=0;
        int count=0;
        for(int i=0; i<n; i++){
            if(dp[i]>max){
                max = dp[i];
                count = ans[i];
            }
            else if(dp[i]==max){
                count += ans[i];
            }
        }
        return count;
    }
};