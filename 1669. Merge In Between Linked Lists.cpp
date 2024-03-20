class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr1 = list1;
        for (int i = 0; i < a - 1; ++i)
            ptr1 = ptr1->next;
        
        ListNode* ptr2 = ptr1->next;
        for (int i = 0; i < b - a + 1; ++i)
            ptr2 = ptr2->next;
        
        ptr1->next = list2;
        while (list2->next)
            list2 = list2->next;
        list2->next = ptr2;
        
        return list1;
    }
};
