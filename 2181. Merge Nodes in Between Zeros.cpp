class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        int sum = 0;
        while(curr != NULL){
            if(curr->val == 0){
                prev->next->val = sum;
                prev->next->next = curr->next;
                prev = prev->next;
                sum = 0;
            }
            sum += curr->val;
            curr = curr->next;
        }
        return head->next;
    }
};
