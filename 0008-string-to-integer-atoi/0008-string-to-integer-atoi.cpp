class Solution {
public:
    int myAtoi(string s) {
        double ans = 0;
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        bool pos = s[i]=='+';
        bool neg = s[i]=='-';
        if(pos){
            i++;
        }
        if(neg){
            i++;
        }
        while(i<s.length() && s[i]>='0' && s[i]<='9'){
                ans = ans*10 + (s[i]-'0');
                i++;
        }
        if(neg){
            ans*=-1;
        }
        if(ans < INT_MIN){
            return INT_MIN;
        }
        if(ans > INT_MAX){
            return INT_MAX;
        }
        return ans;
    }
};