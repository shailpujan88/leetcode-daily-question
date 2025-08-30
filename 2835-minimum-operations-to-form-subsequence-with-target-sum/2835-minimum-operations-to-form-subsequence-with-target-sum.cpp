class Solution {
public:
    int minOperations(vector<int>& nums, int m) {
        vector<int> c(31, 0);
        long long s = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            c[int(log2(x))]++;
            s += x;
        }

        if (s < m) {
            return -1;
        }

        int i = 0, res = 0;
        while (i < 30) {
            if ((1 << i) & m) {
                if (c[i] > 0) {
                    c[i]--;
                } else {
                    while (i < 30 && c[i] == 0) {
                        i++;
                        res++;
                    }
                    c[i]--;
                    continue;
                }
            }
            c[i + 1] += c[i] / 2;
            i++;
        }
        
        return res;
    }
};