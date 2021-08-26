class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(!nums.size())   return 0;
        biggest = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>biggest){
                track_length++;
                biggest = nums[i];
                ans = max(track_length, ans);
            }else{
                track_length=1;
                biggest = nums[i];
            }
        }
        return ans;
    }
private:
    int track_length = 1;
    int biggest = 0;
    int ans=1;
};