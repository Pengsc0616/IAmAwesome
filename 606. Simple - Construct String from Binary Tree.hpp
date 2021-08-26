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
    string tree2str(TreeNode* t) {
        if(!t)  return "";
        string s = std::to_string(t->val);
        string l = tree2str(t->left);
        string r = tree2str(t->right);
        
        if((!t->left)&&(!t->right)){
            return s;
        }else if(!t->right){
            return s+"(" +l +")";
        }else{
            return s+"("+l+")("+r+")";
        }
    }
};
// class Solution {
// public:
//     string tree2str(TreeNode* t) {
//         /*
//         [1, 2, 3, 4]
//         ""
//         "1()()"
//         "1(2()())()"
//         "1(2(4)())()"
//         "1(2(4)())(3()())"
        
//         "1(2(4))()"
        
//         [1, 2, 3, null, 4]
//         ""
//         "1()()"
//         "1(2()())()"
//         "1(2()(4))()"
//         "1(2()(4))(3()())"
//         */
//         string ans = "";
//         DFS(t, ans); 
//         return ans;
//     }
// private:
//     int point = 0;
//     void DFS(TreeNode* t, string& ans){
//         if(!t) return;
//         if(t->right){
//             ans = ans.substr(0,point) + std::to_string(t->val) +"()()"+ ans.substr(point);
//             //cout << ans<< endl;
//         }else if(t->left){
//             ans = ans.substr(0,point) + std::to_string(t->val) +"()"+ ans.substr(point);
//             //cout << ans << endl;
//         }else{
//             ans = ans.substr(0,point) + std::to_string(t->val)+ ans.substr(point);
//             //cout << ans << endl;
//         }
//         //if(t->left){
//             while(ans[point]!=')')  point++;
//             //point--;
//         //}
//         DFS(t->left, ans);
//         if(t->right){
//             while(ans[point]!='(') point++;
//             point ++;
//             DFS(t->right, ans);
//         }else{
//             return;
//         }
            
//     }
// };