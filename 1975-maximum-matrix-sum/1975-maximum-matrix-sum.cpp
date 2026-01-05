class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
         int n  = matrix.size();
         long long total = 0;
         int negativeCnt = 0;
         int minAbs = INT_MAX;
         
         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
              int val = matrix[i][j];
              if(val<0) negativeCnt++;
              minAbs = min(minAbs,abs(val));
              total += abs(val);
            }
         }
         if(negativeCnt%2 == 1){
            total -= 2*minAbs;
         }

         return total;
    }
};