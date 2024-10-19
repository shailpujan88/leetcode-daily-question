class Solution {
public:
   int siz(int n){
        int s = 0;
        while(n>0){
            s++;
            n /= 10;
        }
        return s;
    }
    long long findTheArrayConcVal(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        long long ans = 0;
        int i=0;
        int j = nums.size()-1;
        while(i<j){
            ans += nums[i]*pow(10 , siz(nums[j])) + nums[j];
            i++;
            j--;
            if(i==j)
            ans += nums[j];
        }
        return ans;
        
    }
};