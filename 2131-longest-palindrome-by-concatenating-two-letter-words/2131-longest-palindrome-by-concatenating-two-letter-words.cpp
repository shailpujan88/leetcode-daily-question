class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        int palindromeLength = 0;
        bool hasCenter = false;
        
        
        for (auto& [word, count] : wordCount) {
            string reverseWord = word;
            reverse(reverseWord.begin(), reverseWord.end());
            
            if (word == reverseWord) {
                
                int pairs = count / 2;
                palindromeLength += pairs * 4; 
                
                
                if (count % 2 == 1 && !hasCenter) {
                    palindromeLength += 2; 
                    hasCenter = true;
                }
            }
            else if (word < reverseWord && wordCount.count(reverseWord)) {
                
                int pairs = min(count, wordCount[reverseWord]);
                palindromeLength += pairs * 4; 
            }
        }
        
        return palindromeLength;
    }
};