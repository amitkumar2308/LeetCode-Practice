class Solution {
public:
    int solve(int n){
        if(n==0) return 1;
        if(n==1) return 1;

        return solve(n-1) + solve(n-2);

    }
    int climbStairs(int n) {
       return solve(n);
    }
};