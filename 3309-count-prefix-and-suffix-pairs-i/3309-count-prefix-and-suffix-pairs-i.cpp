class Solution {
private:
    bool prefix(string str,string str1){
        if(str.size()>str1.size()){
            return false;
        }
        int n = str.size();
        return str1.substr(0,n) == str;
    }
private:
    bool suffix(string str,string str1){
        if(str.size()>str1.size()){
            return false;
        }
        int k = str1.size();
        int n = str.size();
        return str1.substr(k-n,k) == str;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            string str = words[i];
            for(int j=i+1;j<words.size();j++){
                if(prefix(words[i],words[j]) && suffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};