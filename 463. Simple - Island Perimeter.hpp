class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int ans = 0;
        int each_ans = 4;
        for(int i=0; i<grid[0].size(); i++){
            for(int j=0; j<grid.size(); j++){
                if(grid[j][i]==1){
                    each_ans = 4;
                    if((i>=1)&&(grid[j][i-1]==1))   each_ans-=2;
                    //if((i<=(grid[0].size()-2))&&(grid[j][i+1]==1))   each_ans--;
                    if((j>=1)&&(grid[j-1][i]==1))   each_ans-=2;
                    //if((j<=(grid.size()-2))&&(grid[j+1][i]==1))   each_ans--;
                    ans += each_ans;
                }               
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int count=0, repeat=0;
//         for(int i=0;i<grid.size();i++)
//         {
//             for(int j=0; j<grid[i].size();j++)
//                 {
//                     if(grid[i][j]==1)
//                     {
//                         count ++;
//                         if(i!=0 && grid[i-1][j] == 1) repeat++;
//                         if(j!=0 && grid[i][j-1] == 1) repeat++;
//                     }
//                 }
//         }
//         return 4*count-repeat*2;
//     }
// };