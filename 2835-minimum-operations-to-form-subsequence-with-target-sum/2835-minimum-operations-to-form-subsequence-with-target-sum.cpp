class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        
        long long prefixSum = 0;
        for(int x:nums){
            prefixSum += x;
        }

        if(prefixSum<target) return -1;

        vector<int> count(32,0);
        int ops = 0;
        for(int num:nums){
            int power = (int)log2(num);
            count[power]++;
        
        }

       // int ops = 0;

        for(int i=0; i<31; i++){
            if((target>>i)& 1){
                if(count[i]>0){
                    count[i]--;
                }else{
                    int j=i+1;

                    while(j<31 && count[j]==0){
                        j++;
                    }
                    if(j==31) return -1;

                    ops += (j-i);
                    count[j]--;

                    for(int k=i; k<j; k++){
                        count[k]++;
                    }
                    count[i]--;
                }
            }
            if(i<30){
                count[i+1] += count[i]/2;
            }
        }
    return ops;
    }
};