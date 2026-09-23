class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();

        long long totalSum = 0;

        for(int num : nums){
            totalSum += num;
        }

        if(totalSum < x) return -1;

        long long target = totalSum - x;

        if(target == 0){
            return n;
        }

        int left = 0;
        long long windowSum = 0;
        int maxLength = -1;

        for(int right = 0; right < n; right++){

            // 1. Expand window
            windowSum += nums[right];

            // 2. Shrink window if sum becomes too large
            while(windowSum > target){
                windowSum -= nums[left];
                left++;
            }

            // 3. Valid window found
            if(windowSum == target){
                maxLength = max(maxLength, right - left + 1);
            }
        }

        if(maxLength == -1){
            return -1;
        }

        return n - maxLength;
    }
};