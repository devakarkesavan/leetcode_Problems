class Solution {
public:
    string clearDigits(string str) {
        string k = "";
        for(int i=0;i<str.length();i++){
            if(k.length()==0){
                k+=str[i];
            }
            else if(isdigit(str[i])){
                if(k.length()>0){
                    k.erase(k.begin()+k.length()-1);
                }
            }
            else{
                k+=str[i];
            }
        }
        return k;
    }
};