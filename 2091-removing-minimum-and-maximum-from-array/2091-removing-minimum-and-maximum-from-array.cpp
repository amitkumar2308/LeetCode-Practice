class Solution {
public:
    
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }
        
        int maxIndex = -1;
        int minIndex = -1;

        // max aur min ke index
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi)
                maxIndex = i;

            if (nums[i] == mini)
                minIndex = i;
        }

        int first = min(maxIndex,minIndex);
        int last = max(maxIndex,minIndex);


        int bothFront = last+1;
        int bothlast = n-first;
        int oneFrontOneBack = (first+1)+(n-last);

        return min({bothFront,bothlast,oneFrontOneBack});

        

    }
};