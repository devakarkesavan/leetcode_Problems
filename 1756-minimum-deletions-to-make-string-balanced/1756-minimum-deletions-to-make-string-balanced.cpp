class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int  b = 0;
        for(auto it:s){
            if(it=='b'){
                b++;
            }
            else{
                ans = min(ans+1,b);
            }
        }
        return ans;
    }
};