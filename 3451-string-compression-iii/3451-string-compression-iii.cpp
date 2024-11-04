class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        int count = 0;
        string str="";
        int i = 0;
        while(i<n){
            int count = 0;
            char ch = word[i];
            while(i<n && count<9 && word[i]==ch){
                count++;
                i++;
            }
            str+=to_string(count);
            str+=ch;
        }
        return str;
    }
};