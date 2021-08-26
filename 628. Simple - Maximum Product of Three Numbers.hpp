class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        std::sort(nums.begin(),nums.end(), std::greater<int>());
        
        return max((nums[0]*nums[1]*nums[2]),(nums[0]*nums[len-1]*nums[len-2]));
    }
};