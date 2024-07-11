class Solution {
int i = 0;
public:
string fun(string& s) {
        string result="";
        while(i<s.length()){
            if(s[i]==')'){
                i++;
                reverse(result.begin(),result.end());
                return result;
            }
            else if(s[i]=='('){
                i++;
                string k = fun(s);
                result+=k;
            }
            else{
                result+=s[i];
                i++;
            }
        }
        return result;
}
    string reverseParentheses(string s) {
        return fun(s);
    }
};