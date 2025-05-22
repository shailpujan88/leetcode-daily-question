// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] > 0) break;
        //     if (i == nums.size() - 1) return 0;
        // }
        // for (int i = 0; i < queries.size(); i++) {
        //     int li = queries[i][0];
        //     int ri = queries[i][1];
        //     int val = queries[i][2];

        //     for (int j = li; j <= ri; j++) {
        //         nums[j] -= val;
        //     }

        //     // After applying this query, check if all elements are <= 0
        //     bool allNonPositive = true;
        //     for (int i=0;i<nums.size();i++) {
        //         if (nums[i]> 0) {
        //             allNonPositive = false;
        //             break;
        //         }
        //     }

        //     if (allNonPositive) {
        //         return i + 1; // Return the number of queries used (1-based count)
        //     }
        // }

        // // After all queries, nums still has values > 0
        // return -1;


class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> remaining(nums); // Copy of nums to apply queries
        int countPositive = 0;

        // Step 1: Count how many elements are initially > 0
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) countPositive++;
        }

        // Step 2: If already all nums are <= 0, return 0
        if (countPositive == 0) return 0;

        // Step 3: Process each query
        for (int q = 0; q < queries.size(); q++) {
            int l = queries[q][0];  // start index
            int r = queries[q][1];  // end index
            int val = queries[q][2]; // value to subtract

            // Apply subtraction on the copy `remaining`
            for (int i = l; i <= r; i++) {
                if (remaining[i] > 0) {  // only consider positive values
                    int before = remaining[i];
                    remaining[i] -= val;  // subtract value

                    if (remaining[i] <= 0) {
                        countPositive--;  // reduce count if it becomes non-positive
                    }
                }
            }

            // Step 4: After each query, check if all elements are <= 0
            if (countPositive == 0) return q + 1;  // queries are 1-based
        }

        // Step 5: If after all queries, some elements are still > 0
        return -1;
    }
};

//     }
// };
