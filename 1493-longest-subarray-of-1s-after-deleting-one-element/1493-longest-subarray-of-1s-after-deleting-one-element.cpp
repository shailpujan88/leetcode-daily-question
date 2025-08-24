class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int countzero=0;
       int window=0;
       int start=0;
       for(int i=0;i<nums.size();i++){
        countzero+=(nums[i]==0);
        while(countzero>1){
            countzero-=(nums[start]==0);
            start++;
        }
        window=max(window,i-start);
       } 
       return window;
    }
};