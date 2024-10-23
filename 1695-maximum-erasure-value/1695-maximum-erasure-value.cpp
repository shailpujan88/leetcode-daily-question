class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxValue = 0; // Maximum sum of unique subarray found so far.
        int sum = 0;      // Current sum of the subarray.
        int i = 0;        // Left pointer for the sliding window.
        int j = 0;        // Right pointer for the sliding window.
        int n = nums.size(); // Size of the input array.

        // Iterate with the right pointer j through the entire array.
        while(j < n)
        {
          sum += nums[j];
            mp[nums[j]]++;
             while(mp[nums[j]] > 1)
            {
                mp[nums[i]]--;
                sum -= nums[i++]; // Move the left pointer to the right.
            }
            maxValue = max(sum, maxValue);
            
            // Move the right pointer to the next position.
            j++;
        }

        // Return the maximum sum of the unique subarray found.
        return maxValue;
    }
};