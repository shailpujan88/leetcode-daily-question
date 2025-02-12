class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxMap;
        int ans = -1;

        for (int num : nums) {
            int sum = digitSum(num);
            if (maxMap.find(sum) != maxMap.end()) {
                ans = max(ans, maxMap[sum] + num);
                maxMap[sum] = max(maxMap[sum], num);
            } else {
                maxMap[sum] = num;
            }
        }

        return ans;
    }
};
