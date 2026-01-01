class Solution {
public:

/*
Loop through the digits from the last one to the first one.
If adding 1 to a digit doesn’t result in 10 (no carry-over), simply increment that digit by 1 and return the list.
If adding 1 results in 10, set that digit to 0 and move to the next digit (left side).
If the first digit is reached and there’s still a carry (i.e., all digits are 9), insert 1 at the start of the list.
Return the updated list of digits.
*/
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
            
   return digits;
    }
};
  