/*
Pseudocode:
1. Initialize a stack to keep track of digits for building the result.
2. Traverse the input string 'num' character by character:
   a. While the stack is not empty, the top of the stack is greater than the current character,
      and we still need to remove digits (k > 0):
      i. Pop the top of the stack (remove the larger digit).
      ii. Decrement k (reduce the number of digits left to remove).
   b. If the stack is empty and the current character is '0' (leading zero), skip adding it.
   c. Otherwise, push the current character onto the stack.
3. If there are still more digits to remove after the loop, keep popping from the stack until k == 0.
4. Initialize a string 'ans' to store the final result:
   a. Pop all remaining elements from the stack and add them to 'ans'.
   b. Reverse 'ans' to obtain the correct number order.
5. If no digits remain (empty result), return "0".
6. Otherwise, return the constructed string 'ans' as the smallest possible number.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();  // Length of the input string
        stack<char> st;      // Stack to store digits for processing
        
        // Traverse each digit in the input number
        for (int i = 0; i < n; i++) {
    // Remove the top of the stack if it is greater than the current digit
            // and we still need to remove more digits (k > 0)
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();   // Remove the larger digit
                k--;        // Decrement the count of digits to be removed
            }
            // Push the current digit to the stack if it's not a leading zero
            if (!(st.empty() && num[i] == '0')) {
                st.push(num[i]);
            }
        }
        
        // If there are still more digits to remove, continue popping from the stack
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        int c = 0;      // Counter to check if any digits remain in the stack
        string ans;    // String to store the resulting number
        while (!st.empty()) {
            c++;          // Count the remaining digits
ans.push_back(st.top()); // Add the top element of the stack to the result
            st.pop();                 // Remove the top element
        }
        
        // Reverse the result to get the final number
        reverse(ans.begin(), ans.end());
        
        // If no digits remain, return "0"
        if (c == 0) {
            return "0";
        }
        return ans;  // Return the smallest possible number
    }
};
