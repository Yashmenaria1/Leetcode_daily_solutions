class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (const int num : nums)
            heapify(num);
    }

    int add(int value) {
        heapify(value);
            return minHeap.top();
    }

private:
    const int k;
    priority_queue<int, vector<int>, greater<>> minHeap;

    void heapify(int value) {
        minHeap.push(value);
        if (minHeap.size() > k)
            minHeap.pop();
    }
};
