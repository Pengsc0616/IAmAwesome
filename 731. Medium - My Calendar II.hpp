class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto two:twoTime){
            if(max(start, two.first) < min(end, two.second)){
                return false;
            }
        }
        for(auto one:oneTime){
            int low = max(start,one.first);
            int high = min(end, one.second);
            if(low < high){
                //twoTime[low] = high;
                twoTime.emplace_back(low,high);
            }
        }
        //oneTime[start] = end;
        oneTime.emplace_back(start,end);
        return true;
        
    }
    
private:
    vector<pair<int,int>> oneTime;
    vector<pair<int,int>> twoTime;
};


// class MyCalendarTwo {
// public:
//     MyCalendarTwo() {
        
//     }
    
//     bool book(int start, int end) {
        
//         auto ittwo = two.lower_bound(start);
//         if(ittwo!=two.cend() && ittwo->first<end){
//             return false;
//         }
//         if(ittwo!=two.cbegin() //代表check不是頭 check的前面至少還有一個
//            && (--ittwo)->second>start){
//             return false;
//         }
        
//         auto itone = one.lower_bound(start);
//         if(itone!=one.cend() && itone->first<end){
//             two[itone->first] = min(itone->second, end);
//         }
//         if(itone!=one.cbegin() //代表check不是頭 check的前面至少還有一個
//            && (--itone)->second>start){
//             two[ max(itone->first, start) ] = itone->second;
//         }
//         one[start] = end; //this line might be why it's wrong
        
//         return true;
//     }
    
// private:
//     map<int,int> one;
//     map<int,int> two;
// };
//錯是錯在用map! map同一個first只能有一個second

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */