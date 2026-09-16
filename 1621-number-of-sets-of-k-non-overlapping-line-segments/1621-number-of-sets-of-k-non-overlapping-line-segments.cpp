class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        
        // We need to choose 2k points out of (n + k - 1) points
        int N = n + k - 1;
        int K = 2 * k;
        
        if (K > N) return 0;
        
        long long res = 1;
        // Calculate nCr = N! / (K! * (N-K)!) 
        // We compute this iteratively: (N * (N-1) * ... * (N-K+1)) / (1 * 2 * ... * K)
        for (int i = 1; i <= K; ++i) {
            res = (res * (N - i + 1)) % MOD;
            res = (res * modInverse(i, MOD)) % MOD;
        }
        
        return res;
    }
    
private:
    // Computes (base^exp) % mod using binary exponentiation
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    
    // Finds modular inverse of n under modulo M using Fermat's Little Theorem
    long long modInverse(long long n, long long M) {
        return power(n, M - 2, M);
    }
};