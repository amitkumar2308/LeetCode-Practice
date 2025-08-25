class Solution {
public:
    int solve(vector<int>& nums){
       int prev1 = 0; int prev2 = 0;
       for(int num:nums){
        int take = num + prev2;
        int skip = prev1;
        int curr = max(take,skip);
        prev2 = prev1;
        prev1 = curr;
       }
       return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];


        //exlude last house
        vector<int> case1(nums.begin(), nums.end()-1);
        vector<int> case2(nums.begin()+1,nums.end());

        return max(solve(case1),solve(case2));

    }
};