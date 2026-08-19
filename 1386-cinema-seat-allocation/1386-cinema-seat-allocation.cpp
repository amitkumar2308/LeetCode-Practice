class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>>rows;

        for(auto &seat:reservedSeats){
            rows[seat[0]].push_back(seat[1]);
        }

        int ans =(n-rows.size())*2; // if no seats reserved in any row then it confirm we can reset two groups which not overlap like 2,3,4,5 and 6,7,8,9

        //proces each rows which have reserved seats 
        for(auto &[row,seats]:rows){
            bool left = true;
            bool middle = true;
            bool right = true;

            for(int seat:seats){
                if(seat>=2 && seat<=5){
                    left = false;
                }
                if(seat>=4 && seat<=7){
                    middle = false;
                }
                if(seat>=6 && seat <=9){
                    right = false;
                }
            }
            if(left && right){
                ans += 2;
            }else if(left||middle||right){
                ans+=1;
            }
        }
        return ans;
    }
};