class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bits = 0;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while ((bits & nums[right]) != 0) {
                bits ^= nums[left];
                left++;
            }

            bits |= nums[right];
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
