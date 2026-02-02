class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force nums[i] + nums[j] = target;
        //means nums[j] = target - nums[i];
        unordered_map<int,int>mp; //store {key,index}

        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];

            if(mp.find(complement)!=mp.end()){
                return {mp[complement],i};
            }

        mp[nums[i]] = i;
              
        }

    return {};
    }
};