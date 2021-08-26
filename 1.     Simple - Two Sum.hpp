class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0; i<nums.size(); ++i){
            auto index = hash.find(nums[i]);
            if( index!=hash.end() ){
                return {index->second, i};
            }
            hash[target-nums[i]]=i;
        }
        return {};
    }
};