// Pseudocode
// 1. Initialize `n` to the length of the input string `s`.
// 2. If `n` is odd, return `false` because a valid parenthesis sequence requires an even number of characters.
// 3. Initialize `t` (a counter to track balance) to 0 for checking from left to right.
// 4. Iterate over the string from left to right:
//    - If `locked[i] == '0'` (unlockable) or `s[i] == '('`, increment `t`.
//    - Otherwise, decrement `t`.
//    - If `t` becomes negative at any point, return `false` (more ')' than allowed).
// 5. Reinitialize `t` to 0 for checking from right to left.
// 6. Iterate over the string from right to left:
//    - If `locked[i] == '0'` (unlockable) or `s[i] == ')'`, increment `t`.
//    - Otherwise, decrement `t`.
//    - If `t` becomes negative, return `false` (more '(' than allowed).
// 7. If both passes succeed, return `true` (the string can be valid).

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;  // Odd length can't be valid
        
        int t = 0;  // Counter for left-to-right check
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(') 
                t++;
            else 
                t--;
            if (t < 0) return false;  // Unbalanced right parenthesis
        }
        
        t = 0;  // Counter for right-to-left check
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') 
                t++;
            else 
                t--;
            if (t < 0) return false;  // Unbalanced left parenthesis
        }
        
        return true;  // Valid if both passes are balanced
    }
};
