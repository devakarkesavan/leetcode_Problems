class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1; // empty string
        dp[1] = 1; // first char is guaranteed not '0' here

        for (int i = 2; i <= n; ++i) {
            int oneDigit = s[i - 1] - '0';
            int twoDigit = stoi(s.substr(i - 2, 2));

            if (oneDigit >= 1) {
                dp[i] += dp[i - 1];
            }

            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
