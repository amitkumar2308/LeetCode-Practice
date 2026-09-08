class Solution {
public:
    int countCommas(int n) {
         int start = 999;
         int cnt = 0;
         for(int i=start; i<n; i++){
             cnt++;
         }

         return cnt;
    }
};