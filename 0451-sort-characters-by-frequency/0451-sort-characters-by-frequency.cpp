class Solution {
public:
    string frequencySort(string s) {
       unordered_map<int,char>mp;
       string result;
       for(char c:s){
        mp[c]++;
       }
       
       priority_queue<pair<int,char>>pq;
       
       for(auto &it:mp){
        pq.push({it.second,it.first}); //char,freq
       }
       
       while(!pq.empty()){
        auto [freq,ch] = pq.top();
        pq.pop();
        
        result.append(freq,ch);
       }
       
    return result;    
    }
};