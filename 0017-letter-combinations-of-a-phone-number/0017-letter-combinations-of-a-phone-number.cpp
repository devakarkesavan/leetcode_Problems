class Solution {
public:
    void fun(int ind,string digits,vector<string>&ans,vector<string>mpp,string s){
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        }
        int a = digits[ind]-'0';
        for(int i=0;i<mpp[a].size();i++){
            s+=mpp[a][i];
            fun(ind+1,digits,ans,mpp,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        vector<string>mpp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s = "";
        fun(0,digits,ans,mpp,s);
        return ans;
    }
};