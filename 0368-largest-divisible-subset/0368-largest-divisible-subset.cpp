class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1), hash(n);
        sort(nums.begin(),nums.end());
        int maxi=1;
        int lastindex=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
          if(dp[i]>maxi){
            maxi=dp[i];
            lastindex=i;
          }

        }
        vector<int> temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            temp.push_back(nums[lastindex]);

        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};