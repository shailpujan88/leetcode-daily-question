class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> minHeap(nums.begin(), nums.end());
        int operations = 0;

        while (minHeap.top() < k) {
            if (minHeap.size() < 2){ 
                return -1; 
            }
            long xsmall = minHeap.top();
            minHeap.pop();
            long ysmall = minHeap.top();
            minHeap.pop();
            minHeap.push (min(xsmall, ysmall) * 2 + max(xsmall, ysmall));
            operations++;
        }
        return operations;
    }
};