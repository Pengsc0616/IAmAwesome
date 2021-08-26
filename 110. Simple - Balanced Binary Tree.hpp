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
// class Solution {
// 	public:
// 		int height(TreeNode *root) {
// 			if(root == NULL)return 0;
// 			return max(height(root->left), height(root->right)) + 1;
// 		}
// 		bool isBalanced(TreeNode* root) {
// 			if(root == NULL)return true;
// 			return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
// 		}
// };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        Count(root);
        return balance;
    }
private:
    bool balance = true;
    //不能定義在外面 會錯 因為這兩個變數是跟著每一個巢圈去跑的 不是跨巢圈的變數
    //int l_count = 0;
    //int r_count = 0;
    
    int Count(TreeNode* root){
        if(!root) return 0;
        int l_count = Count(root->left);
        //cout << "left is " << l_count<< endl;
        int r_count = Count(root->right);
        //cout << "right is " << r_count <<endl;
        if((l_count==-1)||(r_count==-1))    return -1;
        else if(abs(l_count-r_count)>1){
            //cout << "second: "<< l_count << " " << r_count <<endl;
            balance = false;
            return -1;
        }
        else{
            //cout << "third: "<<l_count << " " << r_count <<endl;
            return max(l_count,r_count)+1;
        }
    }
};


// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         //I want to do it in BFS
//         if(!root)   return true;
//         vector<TreeNode*> current, next;
//         current.push_back(root);
//         int depth = 0;
//         int l_stopLevel = 0;
//         int r_stopLevel = 0;
//         int l_finalLevel = 0;
//         int r_finalLevel = 0;
//         while(!current.empty()){
//             //if(depth-stopLevel>1)   return false;
//             for(auto c:current){
//                 //cout << c->val << " ";
//                 if(c->left) next.push_back(c->left);
//                 else{
//                     if(l_reach==false){
//                         l_stopLevel = depth;
//                         l_reach = true;
//                     }
//                     l_finalLevel = depth;
//                 }
//                 if(c->right) next.push_back(c->right);
//                 else{
//                     if(r_reach==false){
//                         r_stopLevel = depth;
//                         r_reach = true;
//                     }  
//                     r_finalLevel = depth;
//                 }
//             }
//             if(abs(r_finalLevel-l_stopLevel)>1)  return false;
//             if(abs(l_finalLevel-r_stopLevel)>1)  return false;
//             //cout << endl;
//             current.swap(next);
//             next.clear();
//             depth++;
//         }
//         return true;
//     }
// private:
//     bool l_reach = false;
//     bool r_reach = false;
// };