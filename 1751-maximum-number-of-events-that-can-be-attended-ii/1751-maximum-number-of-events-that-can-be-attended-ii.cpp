class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        int n = events.size();
        dp = vector<vector<int>>(k + 1, vector<int>(n, -1));
        return dfs(0, k, events);
    }

private:
    vector<vector<int>> dp;

    int dfs(int curIndex, int count, vector<vector<int>>& events) {
        if (count == 0 || curIndex == events.size()) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }
        int nextIndex = bisectRight(events, events[curIndex][1]);
        int skip = dfs(curIndex + 1, count, events);
        int take = events[curIndex][2] + dfs(nextIndex, count - 1, events);
        dp[count][curIndex] = max(skip, take);
        return dp[count][curIndex];
    }

    int bisectRight(vector<vector<int>>& events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
