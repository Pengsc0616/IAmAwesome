class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(prices.empty()){
            prices.push_back(price);
            spans.push_back(1);
            return 1;
        }
        int i = prices.size()-1;
        
        while(prices[i] <= price){
            i -= spans[i];
            if(i < 0){
                // i++;
                break;
            }
        }
        prices.push_back(price);
        spans.push_back(prices.size()-i-1);
        return prices.size()-i-1;
        
    }
private:
    vector<int> prices;
    vector<int> spans;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */