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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)   return {};
        
        vector<TreeNode*> curr,next;
        
        curr.push_back(root);
        
        vector<vector<int>> ans;
        vector<int> sub_ans;
        while(!curr.empty()){
            
            for(const auto & node:curr){
                sub_ans.push_back(node->val);
                if(node->left)  next.push_back(node->left);
                if(node->right)  next.push_back(node->right);
            }
            
            ans.push_back(sub_ans);
            
            sub_ans.clear();
            curr.swap(next);
            next.clear();
        }
        return ans;
    }
};




