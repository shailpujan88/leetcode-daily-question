class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n =nums.size();
        // int ans=0;
        // sort(nums.begin(),nums.end());
        // ans=nums[n/2];
        // return ans;
        int candidate=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(count<=0){
                candidate=nums[i];
            }
            if(candidate==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
    }
};
//tc=o(n)
//sc=o(1)
// i	nums[i]	candidate	count	Action
// 0	  2		   2         1	   Init candidate = 2, count = 1
// 1	  2		   2         2     Same as candidate → count++
// 2	  1		   2 	     1     Different → count--
// 3	  1		   2	     0     Different → count--, now count=0
// 4	  1		   1	     1     count <= 0, so candidate = 1, count++
// 5	  2		   1	     0     Different → count--, count=0
// 6	  2		   2	     1     count <= 0, candidate = 2, count++