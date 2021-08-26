class Trie {
public:
    void insert(string word){
        Trie * root = this;
        for(char w:word){
            w -= 'a';
            if(!root->next[w]){
                //Trie * root->next[w] = new Trie();
                root->next[w] = new Trie();
            }
            root = root->next[w];
        }
        root->is_word = true;
    }
    
//     bool is_prefix(string word){
//         Trie * root = this;
//         for(char w:word){
//             w -= 'a';
//             if(!root->next[w]){
//                 return false;
//             }
//             root = root->next[w];
//         }
//         return true;
//     }
    
// private:
    Trie * next[26] = {};
    bool is_word = false;
    
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie * root = new Trie();
        for(auto word: words){
            root->insert(word);
        }
        
        for(auto word: words){
            if((word.size() < ans.size())
               ||(word.size()==ans.size() && word>ans))  continue;
            Trie * check = root;
            bool mayAnswer = true;
            for(auto w:word){
                w -= 'a';
                if(!check->next[w]->is_word){
                    mayAnswer = false;
                    break;
                }
                check = check->next[w];
            }
            if(mayAnswer)   ans = word;
            
            
            
            
            // string check ="";
            // bool possibleAnswer = true;
            // for(auto w:word){
            //     check += w;
            //     if(!root->is_prefix(check)){
            //         possibleAnswer = false;
            //         break;
            //     }        
            // }
            // if(possibleAnswer)  ans = word;
        }
        return ans;
    }

private:
    string ans = "";
};