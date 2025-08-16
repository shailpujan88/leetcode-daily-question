class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> freq;
       freq[0]=1;
       int prefixsum=0;
       int count=0;
       for(int num:nums){
        prefixsum+=num;
       if(freq.find(prefixsum-k)!=freq.end()){
        count+=freq[prefixsum-k];
       }
       freq[prefixsum]++;
       }
    return count;
    }
};