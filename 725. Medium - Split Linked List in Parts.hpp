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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int totalNum = 0;
        getTotal(head, totalNum);
        cout << totalNum;
        if(totalNum<k){
            while(head){
                pre = head;
                ans.push_back(head);
                head = head->next;
                pre->next = nullptr;
            }
            int blank = k-totalNum;
            while(blank--){
                ans.push_back(nullptr);
            }
            return ans;
        }
        int equal = totalNum/k;
        needAdd = totalNum%k;
        
        int count = 0 ;
        ans.push_back(head);
        Split(head, equal, count);
        return ans;
    }
    
private:
    
    vector<ListNode*> ans;
    int needAdd = 0;
    ListNode * pre;
    
    void getTotal(ListNode* head, int & totalNum){
        if(!head)   return;
        totalNum++;
        getTotal(head->next, totalNum);
        return;
    }
    void Split(ListNode* & head, int equal, int & count){
        if(!head)   return;
        while ((equal+min(1,needAdd))>count){
            if(!head)   break;
            pre = head;
            head = head->next;
            count += 1;
        }
        cout << count << endl;
        if(!head)   return;
        if(needAdd) needAdd--;
        ans.push_back(head);
        pre->next = nullptr;
        count = 0;
        Split(head, equal, count);
        return ;
    }
};
















