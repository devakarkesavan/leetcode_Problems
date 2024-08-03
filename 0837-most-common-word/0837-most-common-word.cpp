class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>st(banned.begin(),banned.end());
        string val = "";
        unordered_map<string,int>mpp;
        int maxi = 0;
        string ans = "";
        for(auto &it:paragraph){
            if(isalpha(it)){
                val+=tolower(it);
            }
            else{
                if(val.length()==0){
                    continue;
                }
                mpp[val]++;
                if(st.find(val)==st.end() && mpp[val] > maxi){
                    maxi = mpp[val];
                    ans = val;
                }
                val="";
            }
        }
        if(val.length()>0){
            mpp[val]++;
                if(st.find(val)==st.end() && mpp[val] > maxi){
                    maxi = mpp[val];
                    ans = val;
                }
        }
        return ans;
    }
};