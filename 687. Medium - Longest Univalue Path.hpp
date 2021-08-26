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
    int longestUnivaluePath(TreeNode* root) {
        if(!root)   return 0;
        int ans=0;
        Travel(root, &ans);
        
        return ans;
    }
private:
    //int ans=0;
    int Travel(TreeNode* root, int *ans){
        if(!root)   return 0;
        
        int l_leaf = Travel(root->left, ans);
        int r_leaf = Travel(root->right, ans);
        
        int l_accept = (root->left)?((root->left->val==root->val)?l_leaf+1:0):0;
        int r_accept = (root->right)?((root->right->val==root->val)?r_leaf+1:0):0;
        *ans = max(*ans, l_accept+r_accept);
        
        return max(l_accept, r_accept);
        
    }
};

// class Solution {
// public:
//     int longestUnivaluePath(TreeNode* root) {
//         if(!root)   return 0;
//         Travel(root, 0);
        
//         int want=0;
//         for(int i=0; i<=index; i++){
//             want = max(want,ans[i]);
//         }
//         return want;
//         //return std::*max_element(ans.begin(),ans.end());
//     }
// private:
//     vector<int> ans;
//     int index = 0;
    
//     void Travel(TreeNode* root, int num){
//         if(!root)   return ;
//         ans[num]++;
//         Travel(root->left,  (root->left->val == root->val) ?num:++num);
//         Travel(root->right, (root->right->val == root->val)?num:++num);
//         index = num;
//         return;
//     }
    
// };