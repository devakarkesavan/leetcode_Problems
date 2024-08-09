class Solution {
public:
    int hammingWeight(int n) {
        int val = 0;
        while(n!=0){
            val++;
            n &= (n-1);
        }
        return val;
    }
};