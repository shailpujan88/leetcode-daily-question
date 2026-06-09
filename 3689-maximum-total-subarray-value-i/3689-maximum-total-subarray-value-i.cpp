class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maximum1 = INT_MAX, maximum2= INT_MIN;
        for (int x : nums) {
            maximum1 = min(maximum1, x);
            maximum2 = max(maximum2, x);
        }
        return (long long)(maximum2 - maximum1) * k;
    }
};