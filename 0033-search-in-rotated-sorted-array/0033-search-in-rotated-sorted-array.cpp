class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high =nums.size()-1;
        int low=0;

        while(low<=high){
            int mid =(low+high)/2;
            if (nums[mid] == target) return mid;
            if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high=mid-1;
            }
            else {
                low=mid+1;
        }
            }
            else{
            
            if(nums[high]>=target && target>=nums[mid]){
             low=mid+1;
            }
            else {
            high=mid-1;
        }
            }

    }
    return -1;
    }
};