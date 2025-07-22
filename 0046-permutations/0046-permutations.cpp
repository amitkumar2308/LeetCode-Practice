class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>&nums,vector<int>&curr,vector<bool>&used){
         if(curr.size()==nums.size()){
        result.push_back(curr);
        return;
      }

      for(int i=0; i<nums.size(); i++){
        if(used[i]) continue;


        used[i] = true;
        curr.push_back(nums[i]);

        solve(nums,curr,used);

        curr.pop_back();
        used[i] = false;
      }
  
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<int>curr;
      vector<bool>used(nums.size(),false);
      solve(nums, curr, used);  
      return result;
    }
};