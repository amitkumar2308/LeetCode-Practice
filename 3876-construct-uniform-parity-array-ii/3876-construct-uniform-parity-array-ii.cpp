class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

         int minOdd = INT_MAX;

         for(int x:nums1){
            if(x%2!=0){
                minOdd = min(minOdd,x);
            }
         }

         bool allOdd = true;
         for(int x:nums1){
            if(x%2==0 && x<= minOdd){
                allOdd = false;
                break;
            }
         }

         bool allEven = true;
         for(int x:nums1){
            if(x%2 !=0 && x== minOdd){
                allEven = false;
                break;
            }
         }
        return allOdd || allEven;
    }
};