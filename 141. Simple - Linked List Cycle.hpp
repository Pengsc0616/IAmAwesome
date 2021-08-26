/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto f=head;
        auto s=head;
        while(f){
            if(!f->next) return false; //out of the list
            f = f->next->next;
            s = s->next;
            if(f==s) return true;
        }
        return false;
    }
};