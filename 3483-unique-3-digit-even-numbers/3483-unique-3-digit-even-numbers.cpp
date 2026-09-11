class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        for(int d:digits){
            freq[d]++;
        }

        int cnt = 0;

        for(int first=1; first<=9; first++){
            if(freq[first]==0) continue;
            freq[first]--;

            for(int second=0; second<=9; second++){
                if(freq[second]==0)continue;
                freq[second]--;
                for(int third = 0; third<=8; third+=2){
                    if(freq[third]>0) cnt++;
                }

                freq[second]++;
            }
            freq[first]++;
               
        }
    return cnt;
    }
};