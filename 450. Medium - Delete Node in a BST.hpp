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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)   return root;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        if(root->val == key){
            if(root->left==nullptr || root->right==nullptr){
                TreeNode * newNode = root->left==nullptr?root->right:root->left;
                // root->left = root->right = nullptr;
                delete root;
                return newNode;
            }
            TreeNode* leftMin = findMin(root->right);
            
            root->val = leftMin->val;
            // deleteNode(root->right, leftMin->val);
            root->right = deleteNode(root->right, leftMin->val);
            
        }
        
        return root;
    }
private:
    TreeNode * findMin(TreeNode* root){
        if(root->left == nullptr)   return root;
        return findMin(root->left);
    }
};












