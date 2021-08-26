// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
        
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         int ans = 0;
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(matrix[i][j]=='0')   continue;
//                 for(int k = 1; k<=min(i,j)+1; k++){ //邊長
//                     // int left = j-k;
//                     // int up = i-k;
//                     ans[i][j] = sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k];
//                 }
//             }
//         }
        
//     }
// private:
//     vector<vector<int>> sum;
//     vector<vector<int>> ans;
// };
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='0')   continue;
                int k = 0;
                while(i-k>0 && matrix[i-k][j]=='1')   k++;
                int l = 0;
                while(j-l>0 && matrix[i][j-l]=='1')   l++;
                k = min(k,l);
                cout << k;
                for(int c=0; c<=k; c++){
                    int out = 0;
                    for(int a=i; a>=i-c; a--){
                        for(int b=j; b>=j-c; b--){
                            if(matrix[a][b]=='0'){
                                out = 1;
                                break;
                            }
                        }
                    }
                    if(out==0)  ans = max(ans,(c+1)*(c+1));
                    else    break;
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> ans;
};






