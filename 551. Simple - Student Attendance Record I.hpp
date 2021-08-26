class Solution {
public:
    bool checkRecord(string s) {
        // ...A..A....
        // ...LLL...
        
        int ruleFirst = 0;
        int ruleSecond = 0;
        for(const char c:s){
            if(c=='A'){
                ruleFirst++;
                if(ruleFirst>=2){
                    return false;
                }
            }
            else if(c=='L'){
                ruleSecond++;
                if(ruleSecond>=3){
                    return false;
                }
                continue;
            }
            ruleSecond = 0;
        }
        return true;
    }
};