class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int left = 0 , right = n;

        while(left<=right){
              int mid = left+(right-left)/2;

              if(nums[mid]== target) return mid;
              
              if(nums[left]<=nums[mid]){
                 if(target>=nums[left] &&target<=nums[mid]){
                    right = mid-1;
                 }else{
                    left = mid+1;
                 }
              }
              else{
                if(target>nums[mid] && target<=nums[right]){
                   left = mid+1;
                }else{
                    right = mid-1;
                }
              }
        }
    return -1;
    }
};