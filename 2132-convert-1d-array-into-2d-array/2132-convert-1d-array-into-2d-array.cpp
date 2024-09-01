class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        if(original.size()!=m*n){
            return ans;
        }
        int cnt = 0;
        vector<int>val;
        for(int i=0;i<original.size();i++){
            if(cnt==n){
                cnt = 0;
                ans.push_back(val);
                val.erase(val.begin(),val.end());
            }
            cnt++;
            val.push_back(original[i]);
        }
        if(!val.empty()){
            ans.push_back(val);
        }
        return ans;
    }
};