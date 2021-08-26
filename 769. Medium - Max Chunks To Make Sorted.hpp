class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //題目意思就是 -> 哪一些區間還需要sort
        if(arr.size()==1)   return 1;
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==i){
                ans++;
                continue;
            }
            int max = arr[i];
            
            // for(;i<max; i++){
            for(;i<=max; i++){
                if(arr[i]>max){
                    max = arr[i];
                }
            }
            ans++;
            i--;
        }
        return ans;
    }
};

// 0 1 2 3
// 1 2 0 3