class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //    7 1 5 3 6 4
        //    0 0 4 2 5 3
        //min 7 1 1 1 1 1
        int currentMin = prices[0];
        int currentProfit = 0;
        
        for(int i=1; i<prices.size(); i++){
            //if min is me, I will never be the selling day
            if(prices[i]<currentMin){
                currentMin = min(currentMin, prices[i]);
            }
            //currentMin = min(currentMin, prices[i]);
            else{
                currentProfit = max(currentProfit, prices[i]-currentMin);
            }
        }
        return currentProfit;
    }
};