class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
           sort(arr.begin(),arr.end());
           
           vector<vector<int>> ans;
           int diff = INT_MAX;
           int n = arr.size();


           for(int i=0; i<n-1; i++){

            if(arr[i+1]-arr[i]<diff)
               diff = arr[i+1] - arr[i];

           }

           for(int i=0; i<n-1; i++){

            if(arr[i+1]-arr[i]==diff){
                vector<int>p(2);
                p[0] = arr[i];
                p[1] = arr[i+1];
                ans.push_back(p);
            }
            
           }
               
               

    return ans;
    }
};