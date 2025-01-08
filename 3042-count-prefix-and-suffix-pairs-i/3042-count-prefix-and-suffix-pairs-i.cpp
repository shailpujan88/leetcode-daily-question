/*
Pseudocode:
1. Initialize `n` as the size of the `words` array and `ans` to store the count of matching prefix-suffix pairs.
2. Iterate through each word `s1` in the `words` array:
   - For each `s1`, iterate over the words following it in the array to compare it with `s2`.
3. For each pair (`s1`, `s2`):
   - Skip further checks if `s2` is shorter than `s1`.
   - Extract the prefix of `s2` of length equal to `s1`.
   - Extract the suffix of `s2` of length equal to `s1`.
   - Check if both the prefix and suffix are equal to `s1`.
   - If true, increment the `ans` counter.
4. Return `ans` as the total count of prefix-suffix matches.
*/

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            string s1 = words[i];

            for (int j = i + 1; j < n; j++) {
                string s2 = words[j];

                // Skip if s2 is shorter than s1
                if (s2.length() < s1.length()) 
                    continue;

                // Extract prefix and suffix
                string pre = s2.substr(0, s1.length());
                string suf = s2.substr(s2.length() - s1.length());

                // Check if both prefix and suffix match s1
                if (pre == s1 && suf == s1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
