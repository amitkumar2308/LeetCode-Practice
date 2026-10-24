class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
          int prefixSum = 0;


          for(int i=0; i<nums.size(); i++){
              nums[i] = prefixSum + nums[i];
              prefixSum = nums[i];
          }

          return nums;
    }
};