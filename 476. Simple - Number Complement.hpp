class Solution {
public:
    int findComplement(int num) {
        int copy = num;
        size_t mask = ~0;
        while(copy!=0){ //create mask
            mask <<= 1;
            copy = copy & mask;
            cout << copy << endl;
        }
        
        num = ~num;
        num = num ^ mask;
        return num;
    }
};