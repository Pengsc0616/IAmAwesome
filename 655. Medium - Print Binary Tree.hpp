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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int weight = (1<<height)-1;//2^height -1;    
        
        vector<vector<string>> ans(height, vector<string> (weight,""));
        fillVector(ans, root, 0, 0, weight-1);
        return ans;
    }
private:
    int getHeight(TreeNode* root){
        if(!root)   return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
    void fillVector(vector<vector<string>> &ans, TreeNode* root, int height, int left, int right) {
        if(!root)   return;
        int mid = (left+right)/2;
        ans[height][mid] = std::to_string(root->val);
        
        fillVector(ans, root->left, height+1, left, mid-1);
        fillVector(ans, root->right, height+1, mid+1, right);
        
    }
    
};









