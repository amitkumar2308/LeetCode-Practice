class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int maxi = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                curr++;
                maxi = max(curr,maxi);
            }else{
                curr = 0;
            }
            
        }
    return maxi;
    }
};