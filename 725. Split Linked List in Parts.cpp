class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int len=0;
        ListNode*temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int size=len/k;
        int rem=len%k;
        temp=head;
        for(int i=0;i<k;i++)
        {
            ListNode*end=temp;
            if(rem>0)
            {
                int c=size;
                while(c--)
                {
                    end=end->next;
                }
                ListNode*x=end->next;
                end->next=NULL;
                ans.push_back(temp);
                temp=x;
                rem--;
            }
            else
            {
                if(size==0)
                {
                    ans.push_back(NULL);    
                }
                else
                {
                    int c=size-1;
                    while(c--)
                    {
                    end=end->next;
                    }
                    ListNode*x=end->next;
                    end->next=NULL;
                    ans.push_back(temp);
                    temp=x;
                }
            }
        }
        return ans;
    }
};
