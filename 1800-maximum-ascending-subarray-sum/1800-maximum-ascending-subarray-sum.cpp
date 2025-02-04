
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int sum = nums[0];  // Start with the first element
        int n = nums.size();  // Define the size of the array

        for (int i = 0; i < n - 1; i++) {  // Loop through the array
            if (nums[i] < nums[i + 1]) {
                sum += nums[i + 1];   // Add to the current ascendin sequence
            } else {
                if (sum > ans) {
                ans = sum;// Update the answer if the current sum is larger
                }
                sum = nums[i + 1];// Start a new sequence
            }
        }

        if (sum > ans) {                   // Final check after the loop
            ans = sum;
        }

        return ans;
    }
};
