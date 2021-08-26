/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         ostringstream os;
//         DFS(root, os);
//         cout << os.str();
//         return os.str();
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         //TreeNode* root;
//         istringstream is(data);
//         return Search(is);
//         //Search(root, is);
//         //return root;
//     }
// private:
//     void DFS(TreeNode* root, ostringstream & os){
//         if(!root){
//             os << "N ";
//             return ;
//         }
//         os << root->val << " "; 
//         DFS(root->left, os);
//         DFS(root->right, os);
//     }
//     //void Search(TreeNode* root, istringstream & is){
//     TreeNode* Search(istringstream & is){
//         string s;
//         is >> s;
//         if(s=="N"){
//             return nullptr;
//         }
//         TreeNode* root = new TreeNode(stoi(s));
//         cout << root->val;
//         root->left = Search(is);
//         root->right = Search(is);
//         return root;
//     }
// };
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        DFS(root, os);
        // cout << os.str();
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="N ") return {};
        TreeNode* root;
        istringstream is(data);
        cout << root << endl;//<< "value:"<<*root<<endl;
        Search(root, is);
        // if(root==NULL)   cout<<"yes";
        cout << root <<endl;;//<< "value:"<<*root<<endl;
        // root=nullptr;
        cout << root <<endl;//<<"value:"<<*root<<endl;
        return root;
    }
private:
    
    void DFS(TreeNode* root, ostringstream & os){
        if(!root){
            os << "N ";
            return ;
        }
        os << root->val << " "; 
        DFS(root->left, os);
        DFS(root->right, os);
    }
    void Search(TreeNode* & root, istringstream & is){
        string s;
        is >> s;
        if(s=="N"){
            // cout << "yes it is N";
            return ;
        }
        root = new TreeNode(stoi(s));
        Search(root->left, is);
        Search(root->right, is);
        // if(root->left)  cout << root->left->val;
        // if(root->right) cout << root->right->val;
        return ;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));