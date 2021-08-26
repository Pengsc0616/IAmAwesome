class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size()) return ;
        sum_ = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i=1; i<=matrix.size(); i++){
            for(int j=1; j<=matrix[0].size(); j++){
                sum_[i][j] = matrix[i-1][j-1] + sum_[i][j-1]+sum_[i-1][j]-sum_[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum_[row2+1][col2+1]-sum_[row2+1][col1]-sum_[row1][col2+1]+sum_[row1][col1];
    }
    
private:
    vector<vector<int>> sum_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */