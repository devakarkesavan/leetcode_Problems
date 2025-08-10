class Solution {
public:
    int fun(int n,int r){
        long long ans = 1;
        for(int i=0;i<r;i++){
            ans = ans * (n-i);
            ans = ans/(i+1);
        }
        return (int)ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>val;
            for(int j=1;j<=i;j++){
                val.push_back(fun(i-1,j-1));
            }
            ans.push_back(val);
        }
        return ans;
    }
};