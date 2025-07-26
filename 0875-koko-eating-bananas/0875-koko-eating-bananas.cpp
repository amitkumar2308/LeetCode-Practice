class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int k){
          long long totalHours = 0;
          for(int pile:piles){
            totalHours += (pile+k-1)/k;
          }
        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int answer = right;

        while(left<=right){
            int mid = left+(right-left)/2;
            if(canEatAll(piles,h,mid)){
                answer = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
    return answer;
    }
};