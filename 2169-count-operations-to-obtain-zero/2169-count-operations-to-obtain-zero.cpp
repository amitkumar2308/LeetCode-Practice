class Solution {
public:
    int solve(int num1, int num2){
        if(num1 == 0 || num2==0) return 0;
        
        if(num1>num2){
            return 1+solve(num1-num2,num2);
        }else{
            return 1+solve(num1,num2-num1);
        }

    }
    int countOperations(int num1, int num2) {
        return solve(num1,num2);
    }
};