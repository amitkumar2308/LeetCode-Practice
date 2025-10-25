class Solution {
public:
    struct Compare{
        bool operator()(pair<char,int>& a, pair<char,int>& b){

            return a.second<b.second;

        }
    };
    string frequencySort(string s) {
           unordered_map<char,int>freq;
           for(char c:s){
            freq[c]++;
           }

        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare>pq;

        for(auto& it:freq){
            pq.push({it.first, it.second});
        }

        string result;

        while(!pq.empty()){
            auto[ch, count] = pq.top();
            pq.pop();
            result.append(count,ch);
        }
    return result;
    }
};