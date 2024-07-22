class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>hash('z'+1,{0,0});
        for(auto i:s){
            hash[i] = {hash[i].first+1,i};
        }
        sort(hash.begin(),hash.end());
        string res = "";
        for(auto i:hash){
            res = string(i.first,i.second)+res;
        }
        return res;
    }
};