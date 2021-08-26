class Solution {
public:
    string convertToBase7(int num) {
        bool sigh = 0;
        if(num<0){
            sigh=1;
            num *= (-1);
        }
        string ans;
        do{
            ans = std::to_string(num%7) + ans;
            num /= 7;
        }while(num>0);
        if(sigh==1) ans = "-" + ans;
        return ans;
    }
};