class Solution {
public:
    int climbStairs(int n) {
        //c[n] = c[n-1] + c[n-2]
        
        vector<int> c(n+1, 0);
        c[0] = 1;
        c[1] = 1;
        for(int i=2; i<n+1; i++){
            c[i] = c[i-1] + c[i-2];
        }
        return c[n];
    }
};