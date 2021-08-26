class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        // 128/1 % 10 = 8
        // 128/10 % 10 = 2
        // 128/100 % 10 = 1
        bool yes = true;
        vector<int> ans;
        for(int num=left; num<=right; num++){
            int check = 1;
            int copy = num;
            yes = true;
            while(check<=num){
                copy = num/check;
                copy %= 10;
                if(copy==0 || (num%copy!=0)){
                    yes = false;
                    break;
                }
                check *= 10;
            }
            if(yes){
                ans.push_back(num);
            }
        }
        return ans;
    }
};