class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        /*
        00
        10 11
        20 21 22
        30 31 32 33
        
        p[i][j] = p[i-1][j-1] + p[i-1][j]
        */
        vector<vector<double>> p(100,vector<double>(100, 0));
        p[0][0] = poured;
        for(int i=0; i<query_row; i++){
            for(int j=0; j<=query_glass; j++){
                
                if(p[i][j]>1){
                    p[i+1][j]   += (p[i][j]-1)/2;
                    p[i+1][j+1] += (p[i][j]-1)/2;
                }
            }
        }
        
        return p[query_row][query_glass]>1?1:p[query_row][query_glass];
    }
};