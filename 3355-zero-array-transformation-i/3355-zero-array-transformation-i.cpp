class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //brute force telll time limit exceeded tc=O(q*n)
    //     for(int i=0;i<queries.size();i++){
    //     int li=queries[i][0];
    //     int ri=queries[i][1];
    //    for(int j=li;j<=ri;j++){
    //     nums[j]-=1;
    //             }
    //     }
    //             for(int i=0;i<nums.size();i++){
    //                 if(nums[i]>0) return false;
    //             }
    //             return true;
    int n=nums.size();
    vector<int> diff(n,0);
    for(int i=0;i<queries.size();i++){
        int start=queries[i][0];
        int end=queries[i][1];
        int x=1;
        diff[start]+=x;

        if(end+1<n){
            diff[end+1]-=x;
        }

    }
    int cumsum=0;
    for(int i=0;i<n;i++){
        cumsum+=diff[i];
        if(cumsum<nums[i]) return false;
    }
    return true;
    }
};