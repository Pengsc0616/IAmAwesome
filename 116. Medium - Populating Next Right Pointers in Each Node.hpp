/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            while(!q.empty() && q.front() == nullptr){
                q.pop();
            }
            if(q.empty())   break;
            Node* first = q.front();
            // cout << first->val<<endl;
            q.pop();
            int size = q.size();
            // cout << "size is " << size << endl;
            while(size-->0){
                Node* second = q.front();
                q.pop();
                if(second == nullptr)   continue;
                // cout << first->val << " " << second->val <<endl;
                first->next = second;
                q.push(first->left);
                q.push(first->right);
                first = first->next;
            }
            q.push(first->left);
            q.push(first->right);
            first->next = nullptr;
            
        }
        return root;
        
    }
};












