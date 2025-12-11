class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int distance = (x * x) + (y * y);

            maxHeap.push({distance, i});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;

        while (!maxHeap.empty()) {
            int value = maxHeap.top().second;
            result.push_back(points[value]);
            maxHeap.pop();
        }
        return result;
    }
};