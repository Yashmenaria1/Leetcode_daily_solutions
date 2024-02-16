class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freqMap;
        for(auto num : arr)
            freqMap[num]++;
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto it : freqMap)
            minHeap.push(it.second);
        while(!minHeap.empty() && k > 0){
            k -= minHeap.top();
            if(k >= 0)
                minHeap.pop();
        }
        return minHeap.size();
    }
};
