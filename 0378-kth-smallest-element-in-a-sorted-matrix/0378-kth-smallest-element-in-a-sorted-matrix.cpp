class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        int n = matrix.size();  //no of row
        int m = matrix[0].size(); //no of col
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                minheap.push(matrix[i][j]);
            }
        }

        for(int i=0; i<k-1; i++){
            minheap.pop();

        }

        return minheap.top();
    }
};