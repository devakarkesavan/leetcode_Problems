class Solution {
private:
    string s, p;
    int n = 0, m = 0;
    vector<vector<int>>dp;
public:
    bool solve(int i, int j)
    {
        if(i >= n && j >= m) return true;
        if(j >= m) return false;
        if(i >= n)
        {
            for(int ii = j; ii < m; ii++)
            {
                if((p[ii] == '*') || (ii + 1 < m && p[ii + 1] == '*')) continue;
                else return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(j + 1 < m && p[j + 1] == '*')
        {
            bool left = solve(i, j + 2);
            bool right = ((s[i] == p[j] || p[j] == '.')) ? solve(i + 1, j) : false;
            return dp[i][j] = left || right;
        }
        if((s[i] == p[j] || p[j] == '.'))
            return dp[i][j] = solve(i + 1, j + 1);
        return dp[i][j] = false; 
    }
    bool isMatch(string s, string p) {
        this->s = s; this->p = p;
        this->n = s.size(); this->m = p.size();
        dp.resize(n + 1,vector<int>(m + 1, -1));
        return solve(0,0);
    }
};