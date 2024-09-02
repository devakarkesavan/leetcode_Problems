class Solution {
public:
    int getSum(int a, int b) {
        int val;
        while(b!=0){
            val = a&b;
            a = a^b;
            b= val<<1;
        }
        return a;
    }
};