class Solution {
public:
vector<int> generaterow(int row){
      long long ans=1;
      vector<int>ansRow;
      ansRow.push_back(1);
      for(int column=1;column<row;column++){
        ans=ans*(row-column);
        ans= ans /column;
        ansRow.push_back(ans);
      }
        return ansRow;
      }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};