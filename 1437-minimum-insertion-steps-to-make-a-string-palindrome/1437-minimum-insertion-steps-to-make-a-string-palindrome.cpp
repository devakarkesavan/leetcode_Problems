class Solution {
private:
    int lcs(string &str1, string &str2){
    // Write your code here.
    int n= str1.length();
    int m = str2.length();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // for(int i=0;i<=n;i++){
    //     dp[i][0] = 0;
    // }
    vector<int>prev(m+1,0),cur(m+1,0);
    int ans= 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                cur[j] = 1+prev[j-1];
            }
            else{
                cur[j] = max(prev[j],cur[j-1]);
            }
        }
        prev = cur;
    }
    return prev[m];
}
private:
    int longestPalindromeSubsequence(string s)
{
    string t=s;
    reverse(s.begin(),s.end());
    return lcs(t,s);
}
public:
    int minInsertions(string s) {
        return s.length()-longestPalindromeSubsequence(s);
    }
};