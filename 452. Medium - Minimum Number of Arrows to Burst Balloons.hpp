class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto & a, const auto & b){
           // a[0] < b[0]; 
            return a[1] < b[1]; 
        });
        int ans = 0;
        for(int i=0; i<points.size(); ){//i++){
            int bound = points[i][1];
            while(i<points.size() && points[i][0]<=bound){
                // bound = max(bound, points[i][1]);
                i++;
            }
            ans++;
            //i--;
        }
        return ans;
        
        
        // sort(points.begin(), points.end(), [](const auto & a, const auto & b){
        //    // a[0] < b[0]; 
        //     return a[0] < b[0]; 
        // });
        // for(auto p:points)  cout << p[0] << " " << p[1] << endl;
        // int ans = 0;
        // for(int i=0; i<points.size(); i++){
        //     int bound = points[i][1];
        //     while(i<points.size() && points[i][0]<=bound){
        //         bound = max(bound, points[i][1]);
        //         i++;
        //     }
        //     ans++;
        // }
        // return ans;
    }
};