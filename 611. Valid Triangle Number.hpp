class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)   return 0;
        //sort(nums.rbegin(),nums.rend(),greater<int>()); // 4 3 2 2
        sort(nums.rbegin(),nums.rend());
        int ans=0;
        int move=0;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                move = n-1;
                while(nums[move]+nums[j]<=nums[i]){
                    move--;
                    if(move==j){
                        break;
                    }
                    //cout << "move"<<move<<endl;
                }
                //cout << i<<j<<move<<endl;
                ans += move-j;
            }
        }
        return ans;
    }
};