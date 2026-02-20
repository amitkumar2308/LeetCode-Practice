class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         vector<int>timeline(1001,0);
         for(auto &trip:trips){
            int passenger = trip[0];
            int from = trip[1];
            int to = trip[2];

            timeline[from] += passenger;
            timeline[to] -= passenger;
         }
         int currentpassenger = 0;
        for(int i=0; i<=1000; i++){
            currentpassenger += timeline[i];
            if(currentpassenger>capacity){
                return false;
            }
        }
        
           return true;
              
         
    }
};