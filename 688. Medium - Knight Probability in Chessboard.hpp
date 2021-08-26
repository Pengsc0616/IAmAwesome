class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        
        int move[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-2,1},{-1,2}};
        
        vector<vector<double>> starts(n,vector<double>(n,0));
        starts[row][column] = 1;
        
        // vector<vector<double>> ends(n,vector<double>(n,0));
        for(int i=0; i<k; i++){
            vector<vector<double>> ends(n,vector<double>(n,0));
            for(int j=0; j<n; j++){
                for(int m=0; m<n; m++){
                    if(starts[j][m]==0) continue;
                    for(int l=0; l<8; l++){
                        if(j+move[l][0]<0 || j+move[l][0]>=n || 
                           m+move[l][1]<0 || m+move[l][1]>=n){
                            continue;
                        }
                        ends[j+move[l][0]][m+move[l][1]] += starts[j][m];
                    }
                }
            }
            swap(starts,ends);
            //ends.clear();
        }
        double ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans += starts[i][j];
            }
        }
        return ans/pow(8,k);
    }
};