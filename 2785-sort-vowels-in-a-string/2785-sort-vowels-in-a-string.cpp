class Solution {
public:
    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }

    string sortVowels(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            if (isVowel(c)) freq[c]++;
        }

        string order = "AEIOUaeiou";
        string result;
        int idx = 0;

        for (char c : s) {
            if (!isVowel(c)) {
                result.push_back(c);
            } else {
                while (freq[order[idx]] == 0) idx++;
                result.push_back(order[idx]);
                freq[order[idx]]--;
            }
        }
        return result;
    }
};