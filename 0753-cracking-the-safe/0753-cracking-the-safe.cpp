class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string result;
        string start(n - 1, '0');
        dfs(start, visited, result, n, k);
        result += start;
        return result;
    }
    void dfs(string node, unordered_set<string>& visited, string& result, int n,int k) {
        for(int i=0;i<k;++i){
             string next=node + to_string(i); //string next = node + (char)('0' + i);
             if(!visited.count(next)){
                 visited.insert(next);
                dfs(next.substr(1), visited, result, n, k);
                result += to_string(i); //result+= (char)('0' + i);
             }


        }
    }
};