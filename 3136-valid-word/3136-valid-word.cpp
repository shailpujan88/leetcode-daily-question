class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (int i = 0; i < word.length(); i++) {
            char c = word[i];

            if (!((c >= 'a' && c <= 'z') || 
                  (c >= 'A' && c <= 'Z') || 
                  (c >= '0' && c <= '9'))) {
                return false;
            }

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                hasVowel = true;
            } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                hasConsonant = true;
            }
        }

        return hasVowel && hasConsonant;
    }
};
