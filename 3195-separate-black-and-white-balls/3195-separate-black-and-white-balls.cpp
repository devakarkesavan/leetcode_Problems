class Solution {
public:
    long long minimumSteps(string s) {
        long long black=0;
        long long  swap=0;
        for(char c: s){
            (c=='1')?black++:swap+=black;
        }
        return swap;
    }
};