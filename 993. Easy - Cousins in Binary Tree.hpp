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
    bool isCousins(TreeNode* root, int x, int y) {
        DFS(0, root, x, y, 0);
        
        if((ansX.first!=ansY.first) && (ansX.second==ansY.second))  return true;
        return false;
    }
    
private:
    pair<int, int> ansX;
    pair<int, int> ansY;
    
    void DFS(int parent_val, TreeNode* root, int x, int y, int depth){
        
        if(root==nullptr)   return;
        if(root->val == x){
            ansX.first = parent_val;
            ansX.second = depth;
        }
        if(root->val == y){
            ansY.first = parent_val;
            ansY.second = depth;
        }
        
        DFS(root->val, root->left, x, y, depth+1);
        DFS(root->val, root->right, x, y, depth+1);
        return;
        
    }
};












