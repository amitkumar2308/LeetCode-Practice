class Solution {
public:
    
    bool sumGame(string nums) {
         int n = nums.size();
         int mid = n/2;

         int leftSum = 0;
         int rightSum = 0;

         int leftQ = 0;
         int rightQ = 0;

         for(int i =0; i<mid; i++){
            if(nums[i]=='?'){
                leftQ++;
            }else{
                leftSum += nums[i]-'0';
            }
        }
        //second half

        for(int i=mid; i<n; i++){
            if(nums[i]=='?'){
                rightQ++;
            }else{
                rightSum += nums[i]-'0';
            }
        }
        int diff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;


        // Odd number of extra '?' 
        if (abs(qDiff) % 2 == 1) {
            return true;
        }

        // Equal number of '?' on both sides
        if (qDiff == 0) {
            return diff != 0;
        }

        // Bob can win only if the difference can be
        // exactly compensated.
        return diff != 9 * (rightQ - leftQ) / 2;
    }
};