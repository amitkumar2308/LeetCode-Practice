class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         int n = hand.size();
         if(n%groupSize!=0) return false;
         //sort(hand.begin(),hand.end());
         //vector<vector<int>>result;
         map<int,int>mp;

        for(int x:hand){
            mp[x]++;
        }

        while(!mp.empty()){
            int start = mp.begin()->first;
            for(int i = 0; i<groupSize; i++){
            int num = start + i;
   
            if(mp[num]==0) return false;
            mp[num]--;
            if(mp[num]==0) mp.erase(num);
         

            }
        }

      return true;   
    }
};