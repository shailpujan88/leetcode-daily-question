class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        unordered_set<int> uniquefreq;
        for(auto z:mp){
            uniquefreq.insert(z.second);
        }
        if(mp.size()==uniquefreq.size()){
            return true;
        }
        return false;
    }
};