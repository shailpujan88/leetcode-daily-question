class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int idx = 1; idx < n; idx++) {
            int idx2 = n - idx;
            if ((to_string(idx) + to_string(idx2)).find('0') == string::npos) {
                return {idx, idx2};
            }
        }
        return {};
    }
};