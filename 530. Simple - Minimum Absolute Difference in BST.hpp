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
    int getMinimumDifference(TreeNode* root) {
        
        if(!root) return ans;
        
        getMinimumDifference(root->left);
        
        if(!preNode)   {
            preNode = root;
        }
        else{
            ans = min(ans, (root->val - preNode->val));
            preNode = root;
        }
        
        getMinimumDifference(root->right);
        
        return ans;
    }

private:
    TreeNode* preNode;
    int ans = INT_MAX;
};