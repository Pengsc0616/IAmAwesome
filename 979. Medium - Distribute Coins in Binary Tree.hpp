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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        DFS(root, ans);
        return ans;
    }

private:
    int DFS(TreeNode* root, int & ans){
        
        if(root==nullptr)   return 0;
        
        int value = DFS(root->left, ans) + DFS(root->right, ans);
        
        value += root->val;
        
        
        ans += abs(value-1);
        return value-1;
        
    }

};











