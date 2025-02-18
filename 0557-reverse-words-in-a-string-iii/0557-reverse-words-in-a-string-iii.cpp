class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string result = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(word.begin(), word.end());
                result += word + " ";
                word = "";
            } else {
                word += s[i];
            }
        }
        
        if (!word.empty()) {
            reverse(word.begin(), word.end());
            result += word;
        }

        return result;
    }
};
