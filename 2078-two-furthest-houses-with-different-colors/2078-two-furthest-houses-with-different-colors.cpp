class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int size = colors.size();
        int result_ans =0;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (colors[i] != colors[j]) {
                    result_ans = max(result_ans, j - i);
                }
            }
        }
        return result_ans;
    }
};