class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<1) return 0;

        // int maxi = INT_MIN;
        
        
        // for(int i=0; i<n; i++){
        //     maxi = max(maxi,nums[i]);
        //     int mini = INT_MAX;
           
        //     for(int j=i;j<n;j++){
        //         mini = min(mini, nums[j]);
        //     }

        // if(maxi-mini<=k) return i;
        // }

        // return -1;

        vector<int>suffixMin(n);
        suffixMin[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(nums[i],suffixMin[i+1]);
        }

        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);

            if(maxi-suffixMin[i]<=k){
                return i;
            }
        }
        return -1;
    }
};