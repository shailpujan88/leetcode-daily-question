class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
           }
            }
          for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
          }  
    }
};
// Original:

// [1, 2, 3]
// [4, 5, 6]
// [7, 8, 9]
// After transposing:
// [1, 4, 7]
// [2, 5, 8]
// [3, 6, 9]
// Notice that matrix[0][1] swapped with matrix[1][0], matrix[0][2] with matrix[2][0], and so on.
// We reverse every row of the transposed matrix.

// Before reversing each row:

// [1, 4, 7]
// [2, 5, 8]
// [3, 6, 9]
// After reversing each row:

// [7, 4, 1]
// [8, 5, 2]
// [9, 6, 3]
// \U0001f389 This is the final rotated matrix — exactly what we wanted!
