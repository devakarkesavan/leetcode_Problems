class Solution {
public:
    int numDecodings(string s) {
        int p = 1,prev,n = s.length();
        for(int i=n-1;i>=0;i--){
            int curr = 0;
            if(s[i]!='0'){
                curr = p;
            }
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')){
                curr+=prev;
            }
            prev = p;
            p = curr;
        }
        if(s.empty()){
            return 0;
        }
        return p;
    }
};