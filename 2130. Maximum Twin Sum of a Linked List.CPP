class Solution {
public:
     void rev(ListNode* head){
        ListNode* prev= NULL;
        ListNode* curr= head->next;
        ListNode* nxt= head->next->next;
        
        while(curr){
            curr->next= prev;
            prev= curr;
            curr= nxt;
            if(nxt)nxt= nxt->next;
            else break;
        }
        
        head->next= prev;
    }
    int pairSum(ListNode* head) {
        auto h= head;
        auto t= head;
        while(t->next->next){
            h= h->next;
            t= t->next->next;
        }
        
        rev(h);
        h= h->next;
        
        int ans= 0;
        
        while(h){
            ans= max(ans, head->val+ h->val);
            head=head->next;
            h= h->next;
        }
        
        return ans;
    }
    
};
