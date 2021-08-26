class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // cout<< "value: "<< val << " , m_.count(val): " << m_.count(val)<<endl;
        if(m_.count(val)) return false;
        m_[val] = v_.size();
        v_.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        /*
        5(3) 8(last)
        m_[5]=3, m_[8]=last, v_[3]=5, v_[last]=8
        m_[5]=last(X), m_[8]=3, v_[last]=5(X), v_[3]=8
        */
        //cout<< "value: "<< val << " , m_.count(val): " << m_.count(val)<<endl;
        if(!m_.count(val))  return false;
        int index = m_[val];
        m_[v_.back()] = index;
        // cout<< "remove:value: "<< val << " , m_.count(val): " << m_.count(val)<<endl;
        m_.erase(val);
        // cout<< "remove:value: "<< val << " , m_.count(val): " << m_.count(val)<<endl;
        
        v_[index] = v_.back(); //不能寫成v_[m_[val]] = v_.back()
        //std::swap(v_[m_[val]], v_.back());
        //swap(v_[m_[val]], v_.back());
        v_.pop_back();
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % v_.size();
        return v_[index];
    }
private:
    unordered_map<int,int> m_;
    vector<int> v_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// class RandomizedSet {
// public:
//     /** Initialize your data structure here. */
//     RandomizedSet() {}
    
//     /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//     bool insert(int val) {
//         if(m_.count(val)) return false;
//         m_[val] = vals_.size();
//         vals_.push_back(val);
//         return true;
//     }
    
//     /** Removes a value from the set. Returns true if the set contained the specified element. */
//     bool remove(int val) {
//         if(!m_.count(val)) return false;
//         int index = m_[val];
//         m_[vals_.back()] = index;
//         m_.erase(val);
//         std::swap(vals_[index], vals_.back());
//         vals_.pop_back();
//         return true;
//     }
    
//     /** Get a random element from the set. */
//     int getRandom() {
//         int index = rand() % vals_.size();
//         return vals_[index];
//     }
// private:
//     // val -> index in the array
//     unordered_map<int, int> m_;
//     vector<int> vals_;
// };