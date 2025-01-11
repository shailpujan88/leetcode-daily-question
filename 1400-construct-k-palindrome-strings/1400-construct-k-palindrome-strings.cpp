// Pseudocode
// 1. Create an unordered map `M` to store character frequencies.
// 2. Initialize `Single` to 0 to count characters with odd frequencies.
// 3. Traverse each character in the string `s` and update its count in the map `M`.
// 4. Traverse each entry in the map `M` to check character frequencies:
//    - If the frequency of a character is odd, increment the `Single` counter.
// 5. Return true if the number of odd frequency characters (`Single`) is less than or equal to `k`
//    and `k` is less than or equal to the length of `s`. Otherwise, return false.

class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> M;  // Step 1: Initialize a map to count character frequencies
        int Single = 0;              // Step 2: Initialize a counter for characters with odd frequencies

        // Step 3: Count frequencies of each character in the string
        for (char c : s) {
            M[c]++;
        }

        // Step 4: Count the number of characters with odd frequencies
        for (auto &[ch, freq] : M) {
            if (freq % 2 == 1) {
                Single++;  // Increment for each odd frequency character
            }
        }

        // Step 5: Check if the number of odd frequencies is within bounds
        // Return true if we can form k palindromes
        return (Single <= k && k <= s.size());
    }
};
