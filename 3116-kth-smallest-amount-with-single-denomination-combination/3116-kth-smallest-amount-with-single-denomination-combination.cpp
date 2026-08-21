class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcmll(long long a, long long b, long long limit) {
        long long g = gcdll(a, b);
        
        if (a / g > limit / b)
            return limit + 1;
        
        return (a / g) * b;
    }

    long long countNumbers(vector<int>& coins, long long x) {
        int n = coins.size();
        long long count = 0;

        // Inclusion-Exclusion
        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    lcm = lcmll(lcm, coins[i], x);

                    if (lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            if (bits % 2 == 1)
                count += x / lcm;
            else
                count -= x / lcm;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countNumbers(coins, mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};