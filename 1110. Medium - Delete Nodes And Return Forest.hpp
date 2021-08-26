/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==nullptr)   return {};
        unordered_set<int> s;
        for(auto t:to_delete){
            s.insert(t);
        }
        if(!s.count(root->val)) answer.push_back(root);
        DFS(root, s, 0);
        return answer;
    }
    
private:
    vector<TreeNode*> answer;
    TreeNode* DFS(TreeNode* root, unordered_set<int> s, int isAnswer){
        if(root==nullptr) return root;
        int isDelete = s.count(root->val);
        root->left  = DFS(root->left,  s, isDelete);
        root->right = DFS(root->right, s, isDelete);
        if(isDelete){
            s.erase(root->val);
            return nullptr;
        }
        if(isAnswer)    answer.push_back(root);
        return root;
    }
};
// class Solution {
// public:
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         if(root==nullptr)   return {};
//         unordered_set<int> s;
//         for(auto t:to_delete){
//             s.insert(t);
//         }
//         if(!s.count(root->val)) answer.push_back(root);
//         DFS(nullptr, root, s);
//         return answer;
//     }
    
// private:
//     vector<TreeNode*> answer;
//     void DFS(TreeNode* pre_root, TreeNode* root, unordered_set<int> s, int isAnswer){
        
//         if(root==nullptr)   return;
//         if(s.count(root->val)){
//             s.erase(root->val);
//             pre_root
//         }
//         if(isAnswer) 
//   root=nullptr;
        
//         DFS(root, root->right, s, 0);
//         DFS(root, root->left, s, 0);
        
//         return;
//     }
// };