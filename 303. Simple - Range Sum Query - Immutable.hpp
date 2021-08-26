class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum_ = vector<int>(nums.size(),0);
        
        sum_[0] = nums[0];
        for(int i=1; i<sum_.size(); ++i){
            sum_[i] = sum_[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return sum_[right];
        return sum_[right]-sum_[left-1];
    }
    
private:
    vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */