class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //[ Bellman-Ford's Algorithm ]
        //我用k步到達c = min(  用k-1步到達c , 用k-1步到達u再從u到c )
        //dp[k][c] = min(dp[k-1][u] + f[u][c],  dp[k-1][c])  //dp[i][j] = ...dp[i][k]...
        
        vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX/2));
        for(int i=0; i<dp.size(); i++)  dp[i][src] = 0;
        // int check = 100000000;
        for(int i=1; i<dp.size(); i++){
            //for(int j=1; j<dp[0].size(); j++){
                // check = 100000000;
                for(auto f:flights){
                    // if(f[1] != j)   continue;
                    dp[i][f[1]] = min(dp[i][f[1]], min(dp[i-1][f[0]]+f[2], dp[i-1][f[1]]));
                    // check = min(check, dp[i-1][f[0]]+f[2]);
                }
                // for(int m=0; m<n; m++){
                //     cout << dp[i-1][m]+flights[m][j] << " ";
                //     check = min(check, dp[i-1][m]+flights[m][j]);
                //     cout << check << " ";
                // }
                // dp[i][j] = min(check, dp[i-1][j]);
            //}
        }
        // if(dp[k+1][dst]==100000000) return -1;
        return dp[k+1][dst]>=100000000?-1:dp[k+1][dst];
        
    }
};