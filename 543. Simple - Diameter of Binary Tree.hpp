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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        Travel(root);
        return ans;
    }
    
private:
    
    int ans=0;
    int Travel(TreeNode* root){
        if(!root) return -1;
        
        int l_leaf = Travel(root->left)+1;
        int r_leaf = Travel(root->right)+1;
        ans = max(ans, l_leaf+r_leaf);
        
        return max(l_leaf, r_leaf);
    }
    
};