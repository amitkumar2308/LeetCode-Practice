class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         vector<int> result;

         for(int x:nums){
            if(x!=0){
                result.push_back(x);
            }
         }

         for(int y:nums){
            if(y==0){
                result.push_back(y);
            }
         }
        nums = result;
    }
};