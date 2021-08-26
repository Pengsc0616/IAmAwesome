class Solution {
public:
    int maxArea(vector<int>& height) {
        //the point is, we don't need to memorize the two height of the final answer
        int i = 0;
        int j = height.size()-1;
        int ans = 0;
        int w_height = 0;
        while(i<j){
            w_height = min(height[i], height[j]);
            //the thing is, we don't need to record boths side of height,
            //we just need the lower height becouse if any side of height
            //is higher than that, we need to stop and calculate the area
            if(w_height*(j-i) > ans){
                ans = w_height*(j-i);
            }
            while(height[i] <= w_height && i<j) i++;
            while(height[j] <= w_height && i<j) j--;
        }
        return ans;
    }
};