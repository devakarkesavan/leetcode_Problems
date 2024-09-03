class Solution {
public:
    int fun(int ind1,int ind2,string s,string t,vector<vector<int>>&dp){
        if(ind1<0 | ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int val;
        if(s[ind1]==t[ind2]){
            val =  1+fun(ind1-1,ind2-1,s,t,dp);
        }
        else{
            val =  0 + max(fun(ind1-1,ind2,s,t,dp),fun(ind1,ind2-1,s,t,dp));
        }
        return dp[ind1][ind2] = val;
    }
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m =  t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return fun(n-1,m-1,s,t,dp);
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                int val;
                if(s[ind1-1]==t[ind2-1]){
                    val =  1+dp[ind1-1][ind2-1];
                }
                else{
                    val =  0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
                dp[ind1][ind2] = val;
            }
        }
        return dp[n][m];
    }
};