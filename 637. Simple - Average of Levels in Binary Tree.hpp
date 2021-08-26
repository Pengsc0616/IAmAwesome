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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<TreeNode*> current, next;
        vector<double> ans;
        current = {root};
        //int depth=0;
        while(!current.empty()){
            long long sum = 0;
            //ans.push_back(0);
            for(const auto& c:current){
                sum += c->val;
                if(c->left)    next.push_back(c->left);
                if(c->right)   next.push_back(c->right);
            }
            ans.push_back((static_cast<double>(sum))/current.size());
            //ans[depth] = (static_cast<double>(sum))/current.size();
            current.swap(next);
            next.clear();    
            //depth++;
        }
        return ans;
    }
    
};
// class Solution {
// public:
//     vector<double> averageOfLevels(TreeNode* root) {
//         if(!root)  return {};
//         vector<double> ans;
//         vector<pair<long long,int>> eachLevel; //<Sum, Num>
        
//         DFS(root, 0, eachLevel);
        
//         for(const auto d:eachLevel)
//             ans.push_back((static_cast<double>(d.first))/d.second);
        
//         return ans;
//     }
    
// private:
//     void DFS(TreeNode* root, int depth, vector<pair<long long,int>>& eachLevel){
//         if(!root)   return ;
//         if(depth>=eachLevel.size()) eachLevel.push_back({0,0});
        
//         eachLevel[depth].first += root->val;
//         eachLevel[depth].second++;
        
//         DFS(root->left, depth+1, eachLevel);
//         DFS(root->right, depth+1, eachLevel);
//     }
// };