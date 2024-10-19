class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int stores=-1;
        int n=nums.size();
       for(int j=1;j<n;j++){
        if(nums[j]<nums[j-1]){
            stores=j;
            break;
        }
       }
       if(stores==-1){
        return 0;
       }
       for(int i=stores;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            return -1;
        }
       }
       if(nums[n-1]<=nums[0]){
        return n-stores;
       }
       return -1;
        
    }
};