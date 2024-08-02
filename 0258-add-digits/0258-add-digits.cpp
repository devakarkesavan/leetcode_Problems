class Solution {
public:
    int addDigits(int num) {
        while(to_string(num).size()>1){
            int sum = 0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            num = sum;
        }
        // int sum = 0;
        // while(num){
        //     sum+=num%10;
        //     num/=10;
        // }
        // num = sum;
        return num;
    }
};