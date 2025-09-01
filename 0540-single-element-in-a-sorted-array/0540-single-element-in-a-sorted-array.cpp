class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(); 
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=1; 
        int high =n-2;
        
// staring from index 1 and ending at n-2beacuse to eliminate the some edge cases to make the code clean
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
 // if we on left and the single element id on right half so to eleimiinate the left half 
              if(mid%2==1 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1]){
                low=mid+1;
              }
              else {
                high=mid-1; //eliminate right half if element is on left half
              }
        }
        return -1;
    }
};