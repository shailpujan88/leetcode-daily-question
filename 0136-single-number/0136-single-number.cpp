class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // -->   take Xorr as where we store our vALUE OF xor we are doing
        // -->   we will itterate from i=0->n
        // -->   and we will do xorr^nums[i]
        //  -->  and then return Xorr
        //  -->  eg [4,1,2,1,2]
        //  -->  4^1^2^1^2
        //  -->  4^1^1^2^2 -->1^1=0 && 2^2=0
        //  -->  4^0^0
        //   --> 4-->here we get our single element in our arr
        int Xorr=0;
        for(int i=0;i<nums.size();i++){
            Xorr=Xorr^nums[i];
        }
        return Xorr;
    }
};