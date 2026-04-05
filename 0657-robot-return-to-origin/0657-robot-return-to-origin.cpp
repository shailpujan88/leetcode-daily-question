class Solution {
public:
    bool judgeCircle(string moves) {
        int x_dir = 0;
        int y_dir = 0;
        for (char move: moves) {
            if(move == 'U') {
                y_dir--;
                }
            else if (move == 'D') {
                y_dir++;
            }
            else if (move == 'L'){
                 x_dir--;
            }
            else if (move == 'R') {
                x_dir++;
            }
        }
         if(x_dir == 0 && y_dir == 0) 
         return true;
         return false;
    }
};