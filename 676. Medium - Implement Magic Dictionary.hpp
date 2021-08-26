class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string words:dictionary){
            for(int i=0; i<words.length(); i++){
                char c = words[i];
                words[i] = '*';
                dict_[words].insert(c);
                words[i] = c;
            }
        }
    }
    
    bool search(string searchWord) {
        for(int i=0; i<searchWord.length(); i++){
            char c = searchWord[i];
            searchWord[i] = '*';
            if(dict_.count(searchWord)){
                if(!dict_[searchWord].count(c) || dict_[searchWord].size()>1)
                    return true;
            }
            searchWord[i] = c;
        }
        return false;
    }
    
private:
    unordered_map<string, unordered_set<char>> dict_;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */