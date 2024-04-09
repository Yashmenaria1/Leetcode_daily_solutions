class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        while(true){
            for(int i = 0; i < tickets.size(); i++){
                if (tickets[i] == 0) continue;
                tickets[i]--;
                count++;
                if(tickets[k] == 0) 
                return count;
            }
        }
    }
};
