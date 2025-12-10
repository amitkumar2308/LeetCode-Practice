class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int m = matrix.size(); //rows
         int n = matrix[0].size();//col
         
         int left = 0;
         int right = m*n-1;

         while(left<=right){
            int mid = left+(right-left)/2;
            int row = mid/n;
            int col = mid%n;

            int value = matrix[row][col];
            if(value==target){
               return true;
            }else if(target<value){
                right = mid-1;
            }else{
                left = mid+1;
            }

        }
     return false;
    }
};