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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        return Travel(preorder, postorder, 0, 0, preorder.size());
        
    }
    
private:
    TreeNode * Travel(vector<int> preorder, vector<int> postorder, int pre_in, int pos_in, int length){
        if(length==0)   return nullptr;
        
        TreeNode * root = new TreeNode(preorder[pre_in++]);
        
        if(length==1)   return root;
        
        int find = pos_in;
        while(postorder[find] != preorder[pre_in]) find++;
        int range = find - pos_in + 1;
        
        root->left = Travel(preorder, postorder, pre_in, pos_in, range);
        // root->right = Travel(preorder, postorder, pre_in+range, find+1, length-range-1);
        root->right = Travel(preorder, postorder, pre_in+range, pos_in+range, length-range-1);
        
        
        //滾動數組的是preorder, postorder就只是計算range用
        
        return root;
        
    }
    
};























