class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto word : words){
            int b = 0;
            for(int i=0;i<pref.size();i++){
                if(pref[i]!=word[i]){
                    break;
                }
                else{
                    b++;
                }
            }if(b==pref.size()){
                count++;
            }
        }
        return count;
    }
};