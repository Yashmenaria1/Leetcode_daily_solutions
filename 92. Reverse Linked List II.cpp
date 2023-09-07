class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        ListNode **a = &head, **b;
        for (;m--; n--)
            a = &(*(b=a))->next;
        for (;n--; swap(*b, *a))
            swap(*b, (*a)->next);
        return head;
    }
};
