class Solution {
public:
    int thirdMax(vector<int>& nums) {

       
        long largest  = LONG_MIN;
        long second   = LONG_MIN;
        long third    = LONG_MIN;


        for(int i=0; i<nums.size(); i++){

            int n = nums[i];

            if(n==largest || n==second || n== third) continue;
            

            if(n>largest){
                third =  second;
                second = largest;
                largest = n;
            }else if(n>second){
                  third = second;
                  second = n;
            }else if(n>third){
                  third = n;
            }
        }

         return (third == LONG_MIN) ? largest : third;
    }
};