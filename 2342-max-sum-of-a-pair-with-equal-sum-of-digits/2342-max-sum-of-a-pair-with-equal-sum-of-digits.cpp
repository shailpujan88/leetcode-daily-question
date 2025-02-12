class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
            num = 18
// Step 1: sum = 0 + (18 % 10) = 0 + 8 = 8   → num = 18 / 10 = 1
// Step 2: sum = 8 + (1 % 10) = 8 + 1 = 9   → num = 1 / 10 = 0
// Return sum = 9
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxMap;
        int ans = -1;

        for (int num : nums) {
            int sum = digitSum(num);
            // sum = digitSum(18) = 9

            if (maxMap.find(sum) != maxMap.end()) {
                // maxMap.find(9) != maxMap.end()  // so 9 is not in maxmap
                ans = max(ans, maxMap[sum] + num);
                //maxMap[9] = 18  (from earlier)
                //maxMap[9] + 36 = 18 + 36 = 54
              //ans = max(-1, 54) = 54
                maxMap[sum] = max(maxMap[sum], num);
                //maxMap = { 9: 36, 7: 43 } ans = 54
 
            } else {
                maxMap[sum] = num;
            }
        }

        return ans;
    }
};
