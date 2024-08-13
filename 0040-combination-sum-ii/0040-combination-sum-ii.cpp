class Solution {
public:
    void fun(int ind,vector<vector<int>>&ans,vector<int>&ds,int target,vector<int>&arr){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.emplace_back(arr[i]);
            fun(i+1,ans,ds,target-arr[i],arr);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        fun(0,ans,ds,target,candidates);
        return ans;
    }
};