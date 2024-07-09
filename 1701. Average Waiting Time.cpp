class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long currentTime = 0;
        long long totalWaitingTime = 0;
        
        for(int i = 0; i < customers.size(); i++){
            int arrivalTime = customers[i][0];
            int processingTime = customers[i][1];
            
            currentTime = max((long long)currentTime, (long long)arrivalTime);
            currentTime += processingTime;
            totalWaitingTime += (currentTime - arrivalTime);
        }
        
        return (double)totalWaitingTime / customers.size();
    }
};
