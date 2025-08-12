class Solution {
public:
    void sortColors(vector<int>& nums) {
        // if the sort library is allowed
        // sort(nums.begin(),nums.end());
        // if no allowed the sort library then the below code is brute force
        // code
        // int n = nums.size();
        // for(int i = 0; i < n - 1; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[i] > nums[j]) {
        //             swap(nums[i], nums[j]);
        //         }
        //     }
        // }
        // ✅ Time Complexity: O(n²)
        //✅ Space Complexity: O(1)
        // the below code is optimal approach the DUTCH NATION FLAG ALGORITHM
        int low = 0, mid = 0,
            high = nums.size() - 1; // ✅ Time Complexity: O(n)
                                    // \U0001f9ee Space Complexity // No extra arrays are used.
        while (mid <= high) {
            if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid]==0
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
        }
    }
};
