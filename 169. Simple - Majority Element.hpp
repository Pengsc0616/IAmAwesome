class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        
        for(auto n:nums){
            hash[n]++;
            if(hash[n]>nums.size()/2)   return n;
        }
        return 0;
    }
};