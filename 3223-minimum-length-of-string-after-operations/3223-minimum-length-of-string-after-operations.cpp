/*
Pseudocode:
1. Initialize an array `freq` of size 26 to zero, representing the frequency of each lowercase letter.
2. Initialize an integer `length` to store the result, initially set to 0.
3. Iterate over each character `c` in the input string `s`:
   a. Increment the corresponding index in `freq` using `c - 'a'`.
4. Iterate over each frequency `f` in `freq`:
   a. Skip if `f` is 0 (character does not appear).
   b. If `f` is even, add 2 to `length`.
   c. If `f` is odd, add 1 to `length`.
5. Return `length` as the minimum possible length after deletions.
*/

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);  // Step 1
        int length = 0;           // Step 2

        for (char c : s) {        // Step 3
            freq[c - 'a']++;
        }

        for (int f : freq) {      // Step 4
            if (f == 0) continue;  // Step 4a
            if (f % 2 == 0) {
                length =length+ 2;      // Step 4b
            } else {
                length++;      // Step 4c
            }
        }

        return length;            // Step 5
    }
};
