/*
Pseudocode:
1. Initialize `res` to 0, which will store the maximum score.
2. Sum the first `k` elements of `cardPoints` to initialize `res`.
3. Set `curr` to `res` to track the score of the current combination.
4. Iterate from `k-1` down to `0`:
   - Remove the last element of the current window (`cardPoints[i]`) from `curr`.
   - Add the corresponding element from the end of the array (`cardPoints[cardPoints.size() - k + i]`) to `curr`.
   - Update `res` as the maximum of `res` and `curr`.
5. Return `res` as the maximum possible score.

Time Complexity (TC):  
- **O(k)**: The initial sum computation and the loop to find the maximum score both run in linear time proportional to `k`.

Space Complexity (SC):  
- **O(1)**: Only a few extra variables are used, independent of the size of the input.

*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0;
		
        // First k elements in our window
        for (int i = 0; i < k; i++) {
            res += cardPoints[i];
        }
        
        int curr = res;
        for (int i = k - 1; i >= 0; i--) {
            // Remove the last element of the current window and add a new element from the end
            curr -= cardPoints[i];
            curr += cardPoints[cardPoints.size() - k + i];
			
            // Check the maximum score from any combination
            res = max(res, curr);
        }
        
        return res;
    }
};
