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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        leftSum = rightSum = 0;
        
        DFS(root, x, 0, 0);
        // cout << leftSum << " " << rightSum << endl;
        if(leftSum>(n/2) || rightSum>(n/2) || (n-leftSum-rightSum)-1>(n/2))   return true;
        return false;
    }
    
private:
    int leftSum, rightSum;
    void DFS(TreeNode* root, int x, int isLeft, int isRight){
        if(root==nullptr)   return;
        
        if(isLeft)  leftSum++;
        else if(isRight) rightSum++;
        
        if(root->val == x){
            DFS(root->left,  x, 1, 0);
            DFS(root->right, x, 0, 1);
        }
        else{
            DFS(root->left, x, isLeft, isRight);
            DFS(root->right, x, isLeft, isRight);
        }
        return;
    }
};