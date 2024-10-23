class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size(); 
        int exp_sum, sum=0; 
        //expected sum
        exp_sum = (n+1)*n/2;
        //actual sum
        for(int i=0;i<n;i++)
            sum+=nums[i];
    return exp_sum-sum;
    }
};