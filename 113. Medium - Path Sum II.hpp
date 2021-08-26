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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur_vec;
        fillVector(root, targetSum, cur_vec);
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    
    void fillVector(TreeNode* root, int targetSum, vector<int> cur_vec){
        if(!root)   return;
        if(!root->left && !root->right){
            if(root->val==targetSum)    {
                cur_vec.push_back(root->val);
                ans.push_back(cur_vec);
            }
            return;
        }
        targetSum -= root->val;
        cur_vec.push_back(root->val);
        
        fillVector(root->left, targetSum, cur_vec);
        fillVector(root->right, targetSum, cur_vec);
        return ;
    }
};