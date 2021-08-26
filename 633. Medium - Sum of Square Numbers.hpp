class Solution {
public:
    bool judgeSquareSum(int c) {
        int celling = sqrt(c);
        for(int i=0; i<=celling; i++){
            long long math = round(sqrt(c-i*i));
            if(math*math + i*i ==c)  return true;
        }
        return false;
    }
};