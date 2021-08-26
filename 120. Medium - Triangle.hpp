class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*
        2
        3 4
        6 5 7
        4 1 8 3
        
        2
        5  6
        11 10 13
        15 11 18 16
        */
        int n = triangle.size();
        vector<vector<int>> ans(n, vector<int>(n));
        ans[0][0] = triangle[0][0];
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j==0){
                    ans[i][j] = triangle[i][j]+ans[i-1][j];
                }else if(j==i){
                    ans[i][j] = triangle[i][j]+ans[i-1][j-1];
                }else{
                    ans[i][j] = triangle[i][j]+min(ans[i-1][j],ans[i-1][j-1]);
                }
            }
        }
        return *min_element(ans[n-1].begin(),ans[n-1].end());
        
        
    }
};