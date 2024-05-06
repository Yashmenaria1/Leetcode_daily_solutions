class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;
        head->next = removeNodes(head->next);
        if(head->val < head->next->val){
            return head->next;
        }
        else{
            return head;
        }
    }
};
