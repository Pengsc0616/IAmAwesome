class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //from left or top
        //dp[i][j] = min(dp[i][j-1], dp[i-1][j])
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 && j==0)    dp[i][j] = grid[i][j];
                else if(i==0)    dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(j==0)    dp[i][j] = dp[i-1][j] + grid[i][j];
                else dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                // cout<< i << " " << j << " " <<dp[i][j] <<endl;
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};