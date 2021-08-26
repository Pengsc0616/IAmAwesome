/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1||!l2) return l1?l1:l2;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        
    }
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(!l1) return l2;
//         if(!l2) return l1;
//         ListNode *firstPosition = new ListNode();
//         ListNode *newList = new ListNode();
//         //firstPosition = newList;
//         newList = firstPosition;
//         //ListNode *newList = &dummy; //the positon of "dummy" is "newList"
//         //ListNode *newList = new ListNode();
//         if(l1->val<l2->val) {
//             newList->next = l1;
//             l1=l1->next;
//         }
//         else {
//             newList->next = l2;
//             l2=l2->next;
//         }
        
//         //ListNode *first = newList->next;
//         newList = newList->next;
        
//         while(l1&&l2){
//             if(l1->val<l2->val){
//                 newList->next = l1;
//                 l1 = l1->next;
//                 newList = newList-> next;
//             }else{
//                 newList->next = l2;
//                 l2 = l2->next;
//                 newList = newList-> next;
//             }
//         }
//         if(l1)  newList->next = l1;
//         if(l2)  newList->next = l2;
        
//         //return dummy.next;
//         return firstPosition->next;
//     }
// };