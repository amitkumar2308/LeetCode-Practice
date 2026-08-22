class Solution {
public:
    bool checkDivisibility(int n) {


         int actualN = n;
         int product = 1;
         int sum = 0;

         while(n>0){
            int digit = n%10;
            sum += digit;
            product *= digit;

            n /= 10;
        }

        return actualN%(sum+product) == 0;
    }
};