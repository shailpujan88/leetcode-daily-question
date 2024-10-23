class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>map;
      for(int i=0;i<n;i++){
          map[nums[i]]++;
      }
     for(auto k:nums){
      if(map[k]>=2){
          return true;
        }
      }
        return false;  
    }
};