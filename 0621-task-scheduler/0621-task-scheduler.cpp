class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxFreq = 0;

        for(int task:tasks){
            freq[task-'A']++;
            maxFreq = max(maxFreq,freq[task-'A']);
        }

        int count_max = 0;
        for(int f:freq){
            if(f==maxFreq){
                count_max++;
            }
        }

        int calculatedTime = (maxFreq-1) * (n+1) + count_max;

        return max(calculatedTime,(int)tasks.size());
    }
};