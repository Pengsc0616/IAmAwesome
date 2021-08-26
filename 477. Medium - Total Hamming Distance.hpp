class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int length = nums.size();
        for(int i=0; i<32; i++){
            int one = 0;
            for(auto & n:nums){
                if(n&1) one++;
                n>>=1;
            }
            ans += one*(length-one);
        }
        return ans;
        
    }
};