class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxi = 1;
        // int count=0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]&& dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    } else if (nums[i] > nums[j]&& dp[i] == 1 + dp[j]) {
                        count[i] += count[j];
                    }
                }
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                ans += count[i];
            }
        }
        return ans;
    }
};