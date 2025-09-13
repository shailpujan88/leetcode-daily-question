class Solution {
public:
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxFreqSum(string s) {
    unordered_map<char, int> freq;

    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    int maxVowelFreq = 0;
    int maxConsonantFreq = 0;

    // Loop through the map
    for (auto &p : freq) {
        char c = p.first;
        int count = p.second;
        if (isVowel(c)) {
            maxVowelFreq = max(maxVowelFreq, count);
        } else {
            maxConsonantFreq = max(maxConsonantFreq, count);
        }
    }

    return maxVowelFreq + maxConsonantFreq;
}
};