class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
          ListNode *start = head, *end = head;
    for(int i = 1; i < k; i++)
        start = start->next;
    ListNode *curr = start;
    while(curr->next != nullptr){
        curr = curr->next;
        end = end->next;
    }
    int t = start->val;
    start->val = end->val;
    end->val = t;
    return head;
    }
};
