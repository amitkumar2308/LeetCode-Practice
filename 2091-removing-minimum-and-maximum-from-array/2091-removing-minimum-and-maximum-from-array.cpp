class Solution {
public:
    
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;  
        int mini = INT_MAX;

        for(int i =0; i<n; i++){
            maxi = max(maxi,nums[i]); //maximum
            mini = min(mini,nums[i]); //minimum
        }

        //indices 

        int maxIndex = -1;
        int minIndex = -1;

        for(int i=0; i<n; i++){
            if(nums[i]==maxi){
                maxIndex = i;       //max elemtn index
            }
            if(nums[i]==mini){
                minIndex = i;   // min element index
            }
        }

        //which one come first 

        int first  = min(maxIndex,minIndex);
        int last = max(maxIndex,minIndex);

        //3 possibilites

        //bothfront
        int bothFront = last+1;

        //both from back 
        int bothBack = n-first;

        //one from front & one from back

        int OFOB = (first+1) + (n-last);


        
        return min({bothFront,bothBack,OFOB});
    }
};