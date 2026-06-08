class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        list<int> small;
        list<int> same;
        list<int> big;

        for (auto num : nums) {
            if (num < pivot) {
                small.push_back(num);
            } else if (num > pivot) {
                big.push_back(num);
            } else {
                same.push_back(num);
            }
        }

        small.insert(small.end(), same.begin(), same.end());
        small.insert(small.end(), big.begin(), big.end());

        vector<int> ans;
        for (auto num : small) {
            ans.push_back(num);
        }
        return ans;
    }
};