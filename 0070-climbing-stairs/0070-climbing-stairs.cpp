class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        int c;
        if(n<=1){
            return n;
        }
        for(int i=1;i<=n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};