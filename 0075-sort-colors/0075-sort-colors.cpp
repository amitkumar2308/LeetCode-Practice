class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>result;
        for(int i=0; i<=2; i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[j]== i){
                    result.push_back(nums[j]);
                }
            }
        }
        nums = result;
    }
};