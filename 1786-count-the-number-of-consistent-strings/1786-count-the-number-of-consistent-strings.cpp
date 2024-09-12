class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>v(allowed.begin(),allowed.end());
        int count = 0;
        for(auto word:words){
            int flag = 0;
            for(auto ch:word){
                if(v.find(ch)==v.end()){
                    flag = 1;
                }
            }if(flag==0){
                count++;
            }
        }
        return count;
        }
    
};