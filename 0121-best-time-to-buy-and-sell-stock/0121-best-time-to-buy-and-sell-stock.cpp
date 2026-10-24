class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProfit = INT_MIN;

        for(int i=0; i<prices.size();i++){
            if(prices[i]<buy){
                buy = prices[i];
            }

            maxProfit = max(maxProfit,prices[i]-buy);
        }

        return maxProfit;
    }
};