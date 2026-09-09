class Solution {
public:
    long long countCommas(long long n) {
         long long cnt = 0;
          for (long long start = 1000; start <= n; ) {
            cnt += n - start + 1;

            if (start > n / 1000) break;
            start *= 1000;
        }

         return cnt;
    }
};