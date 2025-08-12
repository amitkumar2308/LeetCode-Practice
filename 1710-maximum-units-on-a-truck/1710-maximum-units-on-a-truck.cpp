class Solution {
public:
    bool static compare(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    };
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int units = 0;
        sort(boxTypes.begin(),boxTypes.end(),compare);

        for(int i=0; i<n; i++){
            int nb = boxTypes[i][0];
            int nu = boxTypes[i][1];

            if(truckSize>=nb){
                units += nb*nu;
                truckSize-=nb;
            }else{
                units += truckSize*nu;
                break;
            }
        }
    return units;
    }
};