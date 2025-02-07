class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result;
        result.reserve(n);

        unordered_map<int, int> colorMap, ballMap;

        for (const auto& query : queries) {
            int ball = query[0], color = query[1];

            if (ballMap.count(ball)) {
                int prevColor = ballMap[ball];
                if (--colorMap[prevColor] == 0) {
                    colorMap.erase(prevColor);
                }
            }

            ballMap[ball] = color;
            colorMap[color]++;

            result.push_back(colorMap.size());
        }

        return result;
    }
};
