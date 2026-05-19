class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        auto isSafe =
            [&](int x, int y) { return x >= 0 && x  < m && y >= 0 && y < n;};

        vector<vector<int>>dirs{{1,0},{0,1},{-1,0},{0,-1}};

        vector<vector<int>>
            result(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {

            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();

            int x = coord.first;
            int y = coord.second;

            for (auto dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_)) {
                    int absdiff = abs(heights[x][y] - heights[x_][y_]);

                    int maxDiff = max(diff, absdiff);
                    if (result[x_][y_] > maxDiff) {
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        return result[m - 1][n - 1];
    }
};