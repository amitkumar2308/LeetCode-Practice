class Solution {
public:
    int t[501][501];
    int solve(vector<int>& piles,int i, int j){
        if(i>j){
            return 0;
        }

        if(t[i][j]!=-1){
            return t[i][j];
        }

        int take_i = piles[i] + min(solve(piles,i+2,j),solve(piles,i+1,j-1));
        int take_j = piles[j] + min(solve(piles,i,j-2),solve(piles,i+1,j-1));        

        return t[i][j] = max(take_i,take_j);

    }
    bool stoneGame(vector<int>& piles) {
         int n = piles.size();
         memset(t,-1,sizeof(t));
         int sum = accumulate(begin(piles),end(piles),0);

         int Alice_Score = solve(piles,0,n-1);

         return Alice_Score > sum/2;
    }
};