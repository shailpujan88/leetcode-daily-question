/*
Pseudocode:
1. `numberOfSubarrays` function:
   - Return the difference between `sum(nums, k)` and `sum(nums, k - 1)`. This calculates the number of subarrays with exactly `k` odd numbers.
   
2. `sum` helper function:
   - If `k` is negative, return 0.
   - Initialize two pointers `l` and `r` to 0, a variable `sum` to track the count of odd numbers, and `cnt` to count valid subarrays.
   - Iterate through `nums` using `r` as the right pointer:
     - Increment `sum` by 1 if `nums[r]` is odd (`nums[r] % 2`).
     - While `sum` exceeds `k`, move the left pointer `l` to reduce the number of odd elements and adjust `sum`.
     - Increment `cnt` by the number of subarrays ending at `r` (`r - l + 1`).
   - Return `cnt` as the total count of subarrays with up to `k` odd numbers.

3. Time Complexity:
   - **O(2n)**--for 2 while loop
   -**O(2*2n)-->for using sum(nums,k)-sum(nums,k-1)

4. Space Complexity:
   - **O(1)**: Uses only a few variables (`l`, `r`, `sum`, `cnt`) without additional data structures.

*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return sum(nums, k) - sum(nums, k - 1);  // Count exactly k odd subarrays
    }

    int sum(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        while (r < nums.size()) {
            sum += (nums[r] % 2);  // Increment if odd
            while (sum > k) {
                sum -= (nums[l] % 2);  // Decrement if exceeding k
                l++;
            }
            cnt += (r - l + 1);  // Count subarrays ending at r
            r++;
        }
        return cnt;
    }
};
