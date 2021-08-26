class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * root = this;
        for(char w:word){
            w -= 'a';
            if(!root->next[w]){
                root->next[w] = new Trie();
            }
            root = root->next[w];
        }
        root->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * root = this;
        for(char w:word){
            w -= 'a';
            if(!root->next[w]){
                return false;
            }
            root = root->next[w];
        }
        if(root->is_word == true)   return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie * root = this;
        for(char w:prefix){
            w -= 'a';
            if(!root->next[w]){
                return false;
            }
            root = root->next[w];
        }
        return true;
    }
    
private:
    Trie * next[26] = {};
    bool is_word = false;
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */