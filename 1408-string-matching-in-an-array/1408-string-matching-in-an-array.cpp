class Solution {
public:
    vector<string> stringMatching(vector<string>& wordsmatch) {
        vector<string> result;
        int num = wordsmatch.size();
        for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
        if(i != j && wordsmatch[j].find(wordsmatch[i]) != string::npos) {
             result.push_back(wordsmatch[i]);
                    break;
                }
            }
        }
        return result;
    }
};