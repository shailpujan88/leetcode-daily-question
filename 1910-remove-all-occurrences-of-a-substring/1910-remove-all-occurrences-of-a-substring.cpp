class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partl=part.size();
         stack<char> similarw;
        for(int i =0;i<s.size();i++){
            similarw.push(s[i]);

            if(similarw.size()>=partl && match(similarw,part,partl)){
                for(int j=0;j<partl;j++){
                    similarw.pop();
                }
            }
        }
        string result = "";
        while (!similarw.empty()) {
            result = similarw.top() + result;
            similarw.pop();
        }

        return result;
    }
    bool match(stack<char>& similarw, string& part, int partl){
        stack<char> word=similarw;
        for(int k=partl-1;k>=0;k--){
            if(word.top()!=part[k]){
                return false;
            }
            word.pop();
        }
        return true;
    }

};