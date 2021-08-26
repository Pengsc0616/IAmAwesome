class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)    return 0;
        //因為從sqrt(n)~n的每一個數 如果不是倍數的話 其中一個因數一定會小於sqrt(n)
        //所以考慮到sqrt(n)即可
        
        //vector<unsighed char> f(n,1); //1 means prime
        vector<bool> f(n,1);
        
        f[0]=0;
        f[1]=0;
        
        for(int i=2; i<=sqrt(n); i++){
            int j=i;
            while(i*j<=n){
                f[i*j]=0;
                j++;
            }
        }
        /*int ans = 0;
        for(const bool num:f){
            if(num==true)   ans++;
        }*/
        int ans = accumulate(f.begin(), f.end(), 0);
        return ans;
        
    }
};