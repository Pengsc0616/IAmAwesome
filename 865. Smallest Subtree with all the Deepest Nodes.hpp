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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        return FindDeep(root).second;
        
    }
    
private:
    
    pair<int, TreeNode*> FindDeep(TreeNode* root){
        if(root == nullptr){
            return {-1, root};
        }
        auto r = FindDeep(root->right);
        auto l = FindDeep(root->left);
        
        return {max(r.first, l.first)+1,
                    (r.first==l.first)?root:(r.first>l.first)?r.second:l.second};
    }
    
};















