class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int old = (val_.count(key) ? val_[key]:0);
        for(int i=0; i<key.length(); i++){
            //string s = key.substr(0,i+1);
            m_[key.substr(0,i+1)] += (val-old);
        }
        val_[key] = val;
    }
    
    int sum(string prefix) {
        return m_[prefix];
    }
private:
    unordered_map<string,int> val_;
    unordered_map<string,int> m_;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */