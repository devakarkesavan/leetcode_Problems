class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto it:details){
            string k="";
            k+=it[11];
            k+=it[12];
            int l = stoi(k);
            if(l>60){
                cnt++;
            }
        }
        return cnt;
    }
};