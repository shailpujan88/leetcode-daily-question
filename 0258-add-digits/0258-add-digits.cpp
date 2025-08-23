class Solution {
public:
    int addDigits(int num) {
        int ans=0;
      for(int i=0;i<=num.size();i++){
        ans=num[i]+num[i+1];
      }  
      return ans;
    }
};