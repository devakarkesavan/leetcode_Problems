class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>prev(n);
        prev[0] = arr[0];
        for(int i=1;i<n;i++){
            prev[i] = prev[i-1]^arr[i];
        }
        int k = 0;
        vector<int>ans(queries.size());
        for(auto it:queries){
            int i = it[0];
            int j = it[1];
            if(i==0){
                ans[k] = prev[j];
            }
            else{
                ans[k] = prev[i-1]^prev[j];
            }
            k++;
        }
        return ans;
    }
};
