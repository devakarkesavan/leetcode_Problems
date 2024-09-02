class Solution {
public:
    int hammingWeight(int n) {
        int val = 0;
        while(n){
            val++;
            n = n&(n-1);
        }
        return val;
    }
};