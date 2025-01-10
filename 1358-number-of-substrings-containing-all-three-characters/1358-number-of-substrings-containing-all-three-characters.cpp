/*
Pseudocode:
1. Initialize `n` as the size of the string `s` and `cnt` to 0 to store the count of valid substrings.
2. Create a vector `lastseen` of size 3 initialized with -1 to track the last seen indices of characters 'a', 'b', and 'c'.
3. Iterate through the string `s`:
   - Update the last seen index for the current character by `lastseen[s[i] - 'a'] = i`.
   - If all characters 'a', 'b', and 'c' have been seen (none of `lastseen[0]`, `lastseen[1]`, `lastseen[2]` are -1):
     - Increment `cnt` by `1 + min(lastseen)`, representing the number of substrings ending at `i`.
4. Return `cnt` as the final count of substrings containing at least one 'a', 'b', and 'c'.

Time Complexity (TC):
- **O(n)**, where `n` is the length of the string. Each character is processed once, and the `min_element` function operates on a fixed-size array of 3 elements, making it effectively a constant-time operation.

Space Complexity (SC):
- **O(1)**, since we only use a fixed-size vector `lastseen` of size 3 to store indices.

*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<int> lastseen(3, -1);  // Track last seen indices for 'a', 'b', and 'c'
        
        for (int i = 0; i < n; i++) {
            lastseen[s[i] - 'a'] = i;  // Update last seen index for current character
            
            // Check if all characters 'a', 'b', 'c' have been seen
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                cnt += 1 + *min_element(lastseen.begin(), lastseen.end());
            }
        }
        
        return cnt;  // Return the total count of substrings
    }
};
