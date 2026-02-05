class Solution {
public:
    int solve(int left, int right,vector<int>& nums){
        if(left>right) return 0;


        int takeLeft = nums[left] - solve(left+1,right,nums);
        int takeRight = nums[right] - solve(left,right-1,nums);

        return max(takeLeft,takeRight); 

    }
    bool predictTheWinner(vector<int>& nums) {
         return solve(0,nums.size()-1,nums)>=0;
    }
};