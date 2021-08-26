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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr)  return root2; //it returns the rest of the "entire root2"
        //that's why initize is after this because it don't need init anymore.
        if(root2==nullptr)  return root1;
        
        struct TreeNode* ans = new TreeNode(root1->val+root2->val);
        
        ans->left = mergeTrees(root1->left, root2->left);
        ans->right = mergeTrees(root1->right, root2->right);
        return ans;
    }
};
// class Solution {
// public:
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if((!root1)&&(!root2)) return {};
//         //TreeNode* ans;
//         //auto ans = new TreeNode(root1->val+root2->val);
//         struct TreeNode* ans = new TreeNode();
//         DFS(ans, root1, root2);
        
//         return ans;
//     }
// private:
//     void DFS(TreeNode* ans, TreeNode* root1, TreeNode* root2){
//         if((!root1)&&(!root2))  return;

//         if(!root2){
//             ans->val = root1->val;
//             if((root1->left)){
//                 ans->left = new TreeNode();
//                 DFS(ans->left, root1->left, nullptr);
//             }
//             if((root1->right)){
//                 ans->right = new TreeNode();
//                 DFS(ans->right, root1->right, nullptr);
//             }
//         }
//         else if(!root1){
//             ans->val = root2->val;
//             if((root2->left)){
//                 ans->left = new TreeNode();
//                 DFS(ans->left, nullptr, root2->left);
//             }
//             if((root2->right)){
//                 ans->right = new TreeNode();
//                 DFS(ans->right, nullptr, root2->right);
//             }
//         }
//         else{
//             ans->val = root1->val + root2->val;
//             cout<<ans->val;
//             if((root1->left)||(root2->left)){
//                 ans->left = new TreeNode();
//                 DFS(ans->left, root1->left, root2->left);
//             }
//             if((root1->right)||(root2->right)){
//                 ans->right = new TreeNode();
//                 DFS(ans->right, root1->right, root2->right);
//             }
            
//         }
//     }
// };