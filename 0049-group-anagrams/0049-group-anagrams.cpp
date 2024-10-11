class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(auto it:strs){
            string a = it;
            sort(a.begin(),a.end());
            mpp[a].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
            vector<string>k;
            for(auto i:it.second){
                k.push_back(i);
            }
            ans.push_back(k);
        }
        return ans;
    }
};