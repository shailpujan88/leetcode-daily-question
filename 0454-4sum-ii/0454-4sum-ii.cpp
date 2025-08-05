class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        //           int count = 0;

        //         for (int i = 0; i < nums1.size(); i++) {
        //             for (int j = 0; j < nums2.size(); j++) {
        //                 for (int k = 0; k < nums3.size(); k++) {
        //                     for (int l = 0; l < nums4.size(); l++) {
        //                         if (nums1[i] + nums2[j] + nums3[k] + nums4[l]
        //                         == 0) {
        //                             count++;
        //                         }
        //                     }
        //                 }
        //             }
        //         }

        //         return count;
        //     }
        // };
        // brute force
        // O(n⁴) → Very slow for large inputs.

        // \U0001f50d Idea
        //  Break the problem into two parts:

        // Compute all possible sums of pairs from nums1 and nums2, and store
        // their counts in a hashmap.

        // For each pair from nums3 and nums4, check if the negative of their
        // sum exists in the hashmap.

        // This reduces the problem to O(n²) time.
        unordered_map<int, int> sumCount;
        for (auto a : nums1) {
            for (auto b : nums2) {
                sumCount[a + b]++;
            }
        }
        int count = 0;
        for (auto c : nums3) {
            for (auto d : nums3) {
                int target = -(c + d);
                if (sumCount.find(target) != sumCount.end()) {
                    count += sumCount[target];
                }
            }
        }
        return count;
    }
};
//tc -> O(n²)
//sc-> O(n²) 