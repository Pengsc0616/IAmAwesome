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
    int findSecondMinimumValue(TreeNode* root) {
        smallest = root->val;
        return DFS(root);
    }
private:
    int DFS(TreeNode* root){
        if(!root)   return -1;
        if(root->val > smallest){
            return root->val;
        }//else if(root->val == smallest){
        int left_val  = DFS(root->left);
        int right_val = DFS(root->right);
        if(left_val==-1)    return right_val;
        if(right_val==-1)    return left_val;
        return min(left_val, right_val);
    }
    int smallest;
};

// class Solution { //correct answer but ugly
// public:
//     int findSecondMinimumValue(TreeNode* root) {
        
//         if(check==0){
//             check = 1;
//             if(!root)   return -1;
//             smallest = root->val;
//             if(!root->left) return -1;
//             //if(root->left->val==root->right->val)   return -1;
//             //if(root->left->val == root->right->val) return -1;
//         }
//         if(!root)   {
//             if(found==false)    ans=-1;
//             return ans;
//         }
//         if(!root->left){
//             if(found==false)    ans=-1;
//             return ans;
//         }
//         else if(root->left->val == root->right->val){
//             findSecondMinimumValue(root->left);
//             findSecondMinimumValue(root->right);
//         }
//         else if(root->left->val == root->val){
//             ans = min(ans, root->right->val);
//             found=true;
//             findSecondMinimumValue(root->left);
//         }
//         else if(root->right->val == root->val){
//             ans = min(ans, root->left->val);
//             found=true;
//             findSecondMinimumValue(root->right);
//         }
//         return ans;
//     }
// private:
//     int check = 0;
//     int smallest = 0;
//     int ans = INT_MAX;
//     bool found = false; //key is this!!!!!!
// };

// class Solution {
// public:
//     int findSecondMinimumValue(TreeNode* root) {
//         if(!root)   return -1;
//         if(!root->left||!root->right)   return -1;
//         if(root->left->val == root->right->val) return -1;
//         int ans = INT_MAX;
        
//         while(root->right){
//             if(root->left->val != root->val){
//                 ans = min(ans, root->left->val);
//                 if(!root->right)  break;
//                 root = root->right;
//             }else if(root->right->val != root->val){
//                 ans = min(ans, root->right->val);
//                 if(!root->left)  break;
//                 root = root->left;
//             }else   continue;
//         }
//         return ans;     
//     }
// };