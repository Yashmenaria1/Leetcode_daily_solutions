class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return {-1,-1};
        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* next = curr->next;
        vector<int> criticalPoints;
        int pos = 1;
        
        while(next != NULL){
            if(curr->val > prev->val && curr->val > next->val || curr->val < prev->val && curr->val < next->val){
                criticalPoints.push_back(pos);
            }
            prev = curr;
            curr = next;
            next = next->next;
            pos++;
        }

        if (criticalPoints.size() < 2) return {-1, -1};
        int minDis = INT_MAX, maxDis = criticalPoints.back() - criticalPoints.front();

        for (int i = 1; i < criticalPoints.size(); i++) {
            minDis = min(minDis, criticalPoints[i] - criticalPoints[i - 1]);
        }
        return {minDis, maxDis};
    }
};
