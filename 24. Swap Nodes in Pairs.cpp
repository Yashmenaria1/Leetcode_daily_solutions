class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        
        first->next = swapPairs(second->next);
        second->next = first;
        
        return second;
    }
};
