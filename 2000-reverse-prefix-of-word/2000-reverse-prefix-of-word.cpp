class Solution {
public:
    string reversePrefix(string word, char ch) {
        string s = "";
        for (int i = 0; i < word.size(); i++) {
            s += word[i];
            if (word[i] == ch) {
                reverse(s.begin(), s.end());
                break;
            }
        }
        return s + word.substr(s.size()); 
    }
};
