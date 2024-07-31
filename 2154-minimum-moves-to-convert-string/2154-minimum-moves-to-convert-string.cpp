class Solution {
public:
    int minimumMoves(string s) {
        int cnt= 0;
        int val = 0;
        int i;
        for(i=0;i<s.length();i++){
            if(s[i]=='X'){
                i+=2;
                cnt++;
            }
        }
        return cnt;
    }
};