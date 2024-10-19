class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Xorr=0;
        for(int i=0;i<nums.size();i++){
            Xorr=Xorr^nums[i];
        }
        return Xorr;
    }
};