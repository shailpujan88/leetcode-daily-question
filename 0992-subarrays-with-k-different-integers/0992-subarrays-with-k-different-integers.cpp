// Pseudocode
// 1. Define a function `subarraysWithKDistinct` that returns the count of subarrays with exactly k distinct integers.
// 2. Use helper function `counter(nums, k)` to calculate the number of subarrays with at most k distinct integers.
// 3. The result is `counter(nums, k) - counter(nums, k-1)` since the difference gives exactly k distinct subarrays.

// Function `counter(nums, k)`:
// 1. Initialize `maxlen` to 0, left pointer `l` to 0, and right pointer `r` to 0.
// 2. Use a map `mpp` to track the frequency of elements in the current window.
// 3. While `r` is within bounds of the array:
//    - Increment the count of `nums[r]` in `mpp`.
//    - If `mpp` size exceeds `k`, decrement and remove `nums[l]` as needed until the size is valid.
//    - If `mpp` size is at most `k`, update `maxlen` with the current window size and move `r` forward.
// 4. Return `maxlen` as the result.

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return counter(nums, k) - counter(nums, k - 1);
    }
    
private:
    int counter(vector<int>& nums, int k) {
        int maxlen = 0;
        int l = 0, r = 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        
        while (r < n) {
            mpp[nums[r]]++;
            
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            
            maxlen += r - l + 1;  // Update count of subarrays
            r++;
        }
        
        return maxlen;
    }
};
