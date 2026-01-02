class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
       
        for(int i=0;i<nums.size()-2;i++)
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2])
                return nums[i];
            
        return nums.back();
    } //tc=O(n)
   // sc=o(1)
    // here we are using pegionhole algo which states:
    //There exists a subsequence, where the repeated element must appear more than half.
    //so we r taking window size of 3 
   // the the for loop run till the nums.size-2
   // and then check if nums[i] and nums[i+1] or nums[i+2] is equal if it is equal er will return that number
};

// for (int i = 0; i < nums.size() - 1; i++) {
//         if (nums[i] == nums[i + 1])
//             return nums[i];
//     }
//     return -1; 
// }