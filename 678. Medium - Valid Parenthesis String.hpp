class Solution {
public:
    bool checkValidString(string s) {
        
        int left = 0;
        for(auto c:s){
            if(c=='('){
                left++;
            }
            else{
                left--;
                left = max(0,left);
            }
        }
        if(left!=0)  return false;
        //if(left>0)  return false;
        
        // (((*)***((
        
        
        int right = 0;
        for(auto c:s){
            if(c==')'){
                right++;
            }
            else{
                right--;
            }
            if(right>0) return false;
        }
        
        
        return true;
    }
};