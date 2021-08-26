class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(!nums.size()) return nums;
        if((nums.size()*nums[0].size())!=(r*c)) return nums;
        
        vector<vector<int>> ans(r, vector<int>(c));
        
        for(int i=0; i<r*c; ++i){ //actually is i<(nums.size()*nums[0].size())
            ans[ i/c ][ i%c ] = nums[ i/nums[0].size() ][ i%nums[0].size() ];
        }
        
        return ans;
    }
};